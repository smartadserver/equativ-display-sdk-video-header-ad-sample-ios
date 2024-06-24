//
//  VideoHeaderAdViewController.swift
//  VideoHeaderAdSample
//
//  Created by Loic GIRON DIT METAZ on 23/04/2024.
//

import UIKit
import SASDisplayKit

/**
 This sample shows how to display a banner as a Video Header Ad over a table view.
 
 This integration relies on the SASVideoHeaderAdCell which is available in the project.
 Check its source code for more details or to adapt it for your app.
 
 Note that this particular integration requires the use of a simple `UIViewController`, it
 will not work with a `UITableViewController`.
 */
class VideoHeaderAdViewController: UIViewController, UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate, SASVideoHeaderAdCellDelegate {
    
    // MARK: - Properties
    
    private let TOTAL_NUMBER_OF_ROWS = 40
    
    @IBOutlet weak var tableView: UITableView!
    
    // The ad placement which will be used to load the ad cell.
    //
    // @warning Check your placements carefully: the ad on this placement must use the Video Header-Ad dedicated
    // template otherwise the ad might not be displayed properly (typically the ad will not have a close button
    // or might expand when clicked for videos).
    private let adPlacement = SASAdPlacement(siteId: 507206, pageId: 1579908, formatId: 15048, keywordTargeting: "header01")
    
    private lazy var headerAdCell = {
        tableView.dequeueReusableCell(withIdentifier: SASVideoHeaderAdCell.CELL_REUSE_IDENTIFIER)! as! SASVideoHeaderAdCell
    }()
    
    
    private let refreshControl = UIRefreshControl()
    
    // MARK: - View controller lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        refreshControl.addTarget(self, action: #selector(refreshControlAction), for: .valueChanged)
        tableView.addSubview(refreshControl)
        
        setupHeaderAdCell()
        loadBannerView()
    }
    
    @objc func refreshControlAction() {
        refreshControl.endRefreshing()
        
        // This refresh control does nothing, it is just here to show that we can use a pull to refresh while having a SASVideoHeaderAd…
    }
    
    // MARK: - UIScrollViewDelegate methods
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        // The video header cell must know the current scroll state of the table view:
        // It is forwarded once during the ad cell setup and will then be forwarded for each
        // scroll event.
        headerAdCell.scrollViewDidScroll(offset: scrollView.contentOffset)
    }
    
    // MARK: - Ad logic
    
    func setupHeaderAdCell() {
        // Registering the ad cell as a prototype cell of the table view controller so
        // it can be instantiated as any other cells
        tableView.register(
            UINib(nibName: SASVideoHeaderAdCell.NIB_NAME, bundle: nil),
            forCellReuseIdentifier: SASVideoHeaderAdCell.CELL_REUSE_IDENTIFIER
        )
        
        // Defining the view that will be used as parent for the ad cell when it is stuck
        // on the top of the tableview
        headerAdCell.stickToTopContainerView = self.view
        
        // Adding the view controller as delegate of the ad cell
        headerAdCell.delegate = self
        
        // Adding the current view controller as modal parent view controller:
        // this is the controller the SDK will use if the ad needs to be expanded in a modal state
        headerAdCell.modalParentViewController = self
        
        // The video header cell must know the current scroll state of the table view:
        // It is forwarded once during the ad cell setup and will then be forwarded for each
        // scroll event.
        headerAdCell.scrollViewDidScroll(offset: tableView.contentOffset)
    }
    
    func loadBannerView() {
        // Delegating the ad loading to the ad cell
        headerAdCell.loadAd(with: adPlacement)
    }
    
    // MARK: - Table view delegate & data source
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int  {
        return TOTAL_NUMBER_OF_ROWS
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if indexPath.row == 0 {
            // The video header ad effect works by always setting the header ad cell as the first cell
            // of your table view.
            //
            // The cell will automatically change its size as the user scroll (by calling `scrollViewDidScroll`
            // as seen in the previous methods) and will automatically be removed from its table view and
            // stuck over it when its size reach the minimum ratio (check the `SASVideoHeaderAdCell`
            // class for more info).
            //
            // Note that you don't need to handle the case where no ad can be found or where the ad loading
            // fails for any reason: in this case the ad cell will automatically collapse and will not be
            // visible by the user anymore.
            return headerAdCell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "ContentCell")!
            (cell.viewWithTag(1) as! UILabel).text = "\(indexPath.row)"
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    // MARK: - Video header ad cell delegate
    
    /**
     The ad cell provided in this sample allows you to set a delegate similar to the delegate
     available on a regular banner view.
     
     Implementing it is totally optional as the ad cell will automatically handle its display,
     including when the ad cannot be loaded (it will disappear automatically).
     */
    func videoHeaderAdCell(_ videoHeaderAdCell: SASVideoHeaderAdCell, didLoadWith adInfo: SASAdInfo) {
        NSLog("Video Header-Ad did load with ad info:\n\(adInfo)")
    }
    
    func videoHeaderAdCell(_ videoHeaderAdCell: SASVideoHeaderAdCell, didFailToLoad error: any Error) {
        NSLog("Video Header-Ad did fail to load with error:\n\(error)")
    }
    
    func videoHeaderAdCellClicked(_ videoHeaderAdCell: SASVideoHeaderAdCell) {
        NSLog("Video Header-Ad was clicked")
    }
    
    func videoHeaderAdCellDidClose(_ videoHeaderAdCell: SASVideoHeaderAdCell) {
        NSLog("Video Header-Ad did close")
    }
}
