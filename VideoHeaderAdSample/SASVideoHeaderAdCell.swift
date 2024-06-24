//
//  SASVideoHeaderAdCell.swift
//  VideoHeaderAdSample
//
//  Created by Loic GIRON DIT METAZ on 23/04/2024.
//

import UIKit
import SASDisplayKit

/**
 SASVideoHeaderAdCell delegate.
 */
protocol SASVideoHeaderAdCellDelegate: NSObject {
    /**
     Called when the video header ad cell successfully loads an ad.
     */
    func videoHeaderAdCell(_ videoHeaderAdCell: SASVideoHeaderAdCell, didLoadWith adInfo: SASAdInfo)
    
    /**
     Called when the video header ad cell fails to load an ad.
     
     @note The ad cell will automatically collapse in this case.
     */
    func videoHeaderAdCell(_ videoHeaderAdCell: SASVideoHeaderAdCell, didFailToLoad error: any Error)
    
    /**
     Called when the ad inside the cell is clicked by the user.
     */
    func videoHeaderAdCellClicked(_ videoHeaderAdCell: SASVideoHeaderAdCell)
    
    /**
     Called when the ad cell is closed (when the user click on the top-right close button).
     */
    func videoHeaderAdCellDidClose(_ videoHeaderAdCell: SASVideoHeaderAdCell)
}

class SASVideoHeaderAdCell: UITableViewCell, SASBannerViewDelegate {
    
    // MARK: - Constants
    
    static let NIB_NAME = "SASVideoHeaderAdCell"
    static let CELL_REUSE_IDENTIFIER = "SASVideoHeaderAdCell"
    
    /// Maximum ratio of the ad. The ad will never grow higher than necessary to achieve this ratio.
    ///
    /// @note We recommend a value of 16:9 as it is the typical video ratio, however always check
    /// that it works well for your app and that it does not make navigation too cumbersome for the user.
    static let MAX_RATIO: CGFloat = 16.0 / 9.0
    
    /// Minimum ratio of the ad before it is removed from the table view and stuck over it.
    ///
    /// When the ratio of the ad grows back over this minimum ratio again, the ad cell will be unstuck and
    /// added back to the first cell of the table view.
    static let MIN_RATIO: CGFloat = 32.0 / 9.0
    
    // MARK: - Public properties
    
    /// The delegate of the `SASVideoHeaderAdCell`.
    weak var delegate: SASVideoHeaderAdCellDelegate? = nil
    
    /// The view which will act as the parent of the ad cell view after it has reached its minimum ratio,
    /// when the user scrolls the table view.
    ///
    /// Leaving this value to 'nil' means that the banner will always remains in the table view and will
    /// disappear when the user scrolls.
    weak var stickToTopContainerView: UIView? = nil
    
    /// The modal parent view controller of the current banner.
    ///
    /// @note You should always set a valid modal parent view controller, otherwise most post-click interactions
    /// will not be able to work properly (post-click modal, StoreKit, …).
    weak var modalParentViewController: UIViewController? = nil {
        didSet {
            bannerView.modalParentViewController = modalParentViewController
        }
    }
    
    // MARK: - Private properties
    
    private let bannerView = { SASBannerView(frame: .zero) }()
    
    private var isStuck = false
    private var isClosed = false
    
    private var maxSize: CGFloat {
        return self.bounds.size.width / SASVideoHeaderAdCell.MAX_RATIO
    }
    private var minSize: CGFloat {
        return self.bounds.size.width / SASVideoHeaderAdCell.MIN_RATIO
    }
    
    @IBOutlet weak var adContainerView: UIView!
    @IBOutlet weak var paddingViewHeightConstraint: NSLayoutConstraint!
    @IBOutlet weak var adContainerHeightConstraint: NSLayoutConstraint!
    
    // MARK: - Cell public API
    
    override func awakeFromNib() {
        // Initial video header ad cell setup:
        
        // Settings 'clipsToBounds' to false for both the ad cell and the contentView.
        // This will avoid the video header ad banner to be cropped when the user pulls the table view.
        self.clipsToBounds = false
        self.contentView.clipsToBounds = false
        
        // Unsticking the banner so it is in the right state when added to the table view.
        unstickBanner()
    }
    
    func loadAd(with adPlacement: SASAdPlacement) {
        // Loading the ad cell simply consists in loading a banner view as in other integration case:
        
        bannerView.delegate = self
        bannerView.modalParentViewController = modalParentViewController
        
        bannerView.loadAd(with: adPlacement)
    }
    
    func scrollViewDidScroll(offset: CGPoint) {
        // No need to handle scroll events if the ad is already closed
        guard !isClosed else { return }
        
        // This method handles the table view scroll events:
        
        // The size of the ad container is computed depending on the vertical offset of the table view
        // and the maximum size the ad cell can use.
        let adContainerHeight = maxSize - offset.y
        
        // Then the banner is displayed either inline in the table view or over it depending on
        // the computed size.
        if adContainerHeight > minSize {
            // If the banner height is higher than the minimum size:
            // The banner is unstick if necessary (aka added back to the table view).
            if isStuck {
                unstickBanner()
            }

            // The size of the ad is set using the value computed at the start of the method
            adContainerHeightConstraint.constant = CGFloat(adContainerHeight)
            
            // A padding is added so the ad container stays in the bottom part of the ad cell:
            // this allows the banner view to be always 100% visible.
            paddingViewHeightConstraint.constant = CGFloat(maxSize)
        } else {
            // If the banner height is smaller than the minimum size:
            
            // The banner is stuck if necessary (aka it is removed from the superview and displayed
            // over it, inside the `stickToTopContainerView`).
            if !isStuck {
                stickBanner()
            }
        }
    }
    
    func closeAd() {
        // This method is used to close the ad cell, aka collapse it automatically.
        //
        // Note that this method will be called automatically if the ad cannot be loaded or if the
        // user click on the top-right close button of the ad. But it can also be called manually
        // by the app if necessary.
        
        // The banner view is first removed from its superview (so any ad playback is automatically stopped).
        bannerView.removeFromSuperview()
        
        // The ad cell height is set to zero, then the table view content is reloaded.
        paddingViewHeightConstraint.constant = CGFloat(0.0)
        adContainerHeightConstraint.constant = CGFloat(0.0)
        reloadAdCell()
        
        // A flag is raised so the ad cell stops processing the scroll event.
        isClosed = true
        
        // Call the delegate, if any.
        delegate?.videoHeaderAdCellDidClose(self)
    }
    
    // MARK: - Internal view management
    
    /**
     This util method is used to retrieve the current table view the ad cell is displayed in.
     */
    private func currentTableView() -> UITableView? {
        var view = self.superview
        while view != nil {
            if let tableView = view as? UITableView {
                return tableView
            }
            view = view?.superview
        }
        return nil
    }
    
    /**
     This util method is used to reload table view the ad cell is displayed in.
     */
    private func reloadAdCell() {
        if let tableView = currentTableView() {
            tableView.beginUpdates()
            tableView.endUpdates()
        }
    }
    
    private var bannerHeightConstraint: NSLayoutConstraint? = nil
    
    private func stickBanner() {
        // No need to stick the banner if it is already closed or there is no `stickToTopContainerView` defined
        guard !isClosed else { return }
        guard let mainView = stickToTopContainerView else { return }
        
        // The banner view is removed from its parent (the table view) and added to the 'stick to top' view.
        bannerView.removeFromSuperview()
        mainView.addSubview(bannerView)
        
        // The banner height is now harcoded to the minimum size as user scrolls are ignored as long as the
        // banner view is stuck over the table view.
        bannerHeightConstraint = bannerView.heightAnchor.constraint(equalToConstant: minSize)
        
        // New constraints are applied on the banner view:
        // including the hardcoded height constraint defined above.
        bannerView.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            bannerView.leadingAnchor.constraint(equalTo: mainView.safeAreaLayoutGuide.leadingAnchor),
            bannerView.trailingAnchor.constraint(equalTo: mainView.safeAreaLayoutGuide.trailingAnchor),
            bannerView.topAnchor.constraint(equalTo: mainView.safeAreaLayoutGuide.topAnchor),
            bannerHeightConstraint!,
        ])
        
        // A flag is set so the scroll events are processed properly
        isStuck = true
    }
    
    private func unstickBanner() {
        // No need to unstick the banner if it is already closed
        guard !isClosed else { return }
        
        // The banner view is removed from its parent (the 'stick to top' view) and added to the container of the ad cell
        bannerView.removeFromSuperview()
        adContainerView.addSubview(bannerView)
        
        // The manual height constraint set when the banner was stuck is removed and destroyed.
        if let constraint = bannerHeightConstraint {
            bannerView.removeConstraint(constraint)
            bannerHeightConstraint = nil
        }
        
        // New constraints are applied on the banner view:
        // The banner will simply occupy the whole ad container view (whose size is already computed properly
        // in the method that handles scroll events).
        bannerView.translatesAutoresizingMaskIntoConstraints = false
        NSLayoutConstraint.activate([
            bannerView.leadingAnchor.constraint(equalTo: adContainerView.leadingAnchor),
            bannerView.trailingAnchor.constraint(equalTo: adContainerView.trailingAnchor),
            bannerView.topAnchor.constraint(equalTo: adContainerView.topAnchor),
            bannerView.bottomAnchor.constraint(equalTo: adContainerView.bottomAnchor),
        ])
        
        isStuck = false
    }
    
    // MARK: - Banner view delegate
    
    func bannerView(_ bannerView: SASBannerView, didLoadWith adInfo: SASAdInfo) {
        // Forwarding the banner view delegate call to the ad cell delegate
        delegate?.videoHeaderAdCell(self, didLoadWith: adInfo)
    }
    
    func bannerView(_ bannerView: SASBannerView, didFailToLoad error: any Error) {
        // Forwarding the banner view delegate call to the ad cell delegate
        delegate?.videoHeaderAdCell(self, didFailToLoad: error)
        
        // The ad cell must be closed if no ad can be loaded
        closeAd()
    }
    
    func bannerViewClicked(_ bannerView: SASBannerView) {
        // Forwarding the banner view delegate call to the ad cell delegate
        delegate?.videoHeaderAdCellClicked(self)
    }
    
    func bannerViewDidRequestClose(_ bannerView: SASBannerView) {
        // The ad cell must be closed if the user click on the top-right close button
        closeAd()
    }
    
}
