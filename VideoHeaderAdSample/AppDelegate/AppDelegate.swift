//
//  AppDelegate.swift
//  VideoHeaderAdSample
//
//  Created by Loic GIRON DIT METAZ on 23/04/2024.
//

import UIKit
import SASDisplayKit

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // -----------------------------------------------
        // Equativ Display SDK Configuration
        // -----------------------------------------------
        
        // The SDK must be configured first, otherwise no ad will be retrieved.
        SASConfiguration.shared.configure()
        
        // Enabling logging can be useful to get informations if ads are not displayed properly.
        // Don't forget to turn logging OFF before submitting to the App Store.
        SASConfiguration.shared.loggingEnabled = true
        
        
        // -----------------------------------------------
        // TRACKING AUTHORIZATION
        // -----------------------------------------------
        
        // Starting with iOS 14, the SDK need the user's consent before being able to access the IDFA.
        // Check the 'MainViewController' class to check how to request this consent…
        
        
        // -----------------------------------------------
        // Privacy laws compliancy
        // -----------------------------------------------
        
        // The SDK is able to handle consent generated through a TCF compliant CMP (for GDPR, CCPA, GPP frameworks).
        //
        // If you deploy your app in a country implementing one of these privacy laws, remember to install and setup
        // an IAB compliant CMP!
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

}
