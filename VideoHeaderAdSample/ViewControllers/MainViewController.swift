//
//  ViewController.swift
//  VideoHeaderAdSample
//
//  Created by Loic GIRON DIT METAZ on 23/04/2024.
//

import UIKit

struct MenuItem {
    let title: String
    let segue: String
}

/*
 This view controller acts as a main menu.
 
 To check how the ads are integrated, look at the view controller 'VideoHeaderAdViewController'.
 */
class MainViewController: UITableViewController {
    
    private var items = [
        MenuItem(title: "Video Header Ad", segue: "videoHeaderAdViewControllerSegue")
    ]
    
    // MARK: - Table view delegate & data source
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return items.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "SampleCell")!
        cell.textLabel?.text? = items[(indexPath as NSIndexPath).row].title
        return cell
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int  {
        return 1
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String {
        return "Choose a sample:";
    }
    
    override func tableView(_ tableView: UITableView, titleForFooterInSection section: Int) -> String {
        return "\nThis sample demonstrates how to implement the Equativ SDK in a Swift application."
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        performSegue(withIdentifier: items[(indexPath as NSIndexPath).row].segue, sender: nil)
    }

}
