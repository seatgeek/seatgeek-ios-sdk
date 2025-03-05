# SeatGeekSDK

SeatGeek SDK allows client integrators to bring ticketing experience into their iOS apps.

- For the SeatGeek SDK documentation, please refer to our [developer documentation](https://developer.seatgeek.com).
- For the SeatGeek SDK demo apps, please refer to [seatgeek-ios-sdk-demo](https://github.com/seatgeek/seatgeek-ios-sdk-demo) repository.

![ios](https://img.shields.io/cocoapods/p/ios?color=lightgrey)
![SPM](https://img.shields.io/badge/SPM-Compatible-brightgreen)

## Contents
- [Requirements](https://github.com/seatgeek/seatgeek-ios-sdk#requirements)
- [Features](https://github.com/seatgeek/seatgeek-ios-sdk#features)
- [Communication](https://github.com/seatgeek/seatgeek-ios-sdk#communication)
- [Installation](https://github.com/seatgeek/seatgeek-ios-sdk#installation)

## Requirements
- iOS 16.0+
- XCode 16.2+

## Features
- Ability to view tickets, ticket history
- Ability to list tickets for resale
- Drop-in UI (standard/custom widgets, buttons, etc.)
- SSO (Single sign-on)


## Communication
- If you have any questions, please contact us via Slack for details.

## Installation

#### Swift Package Manager
[Swift Package Manager](https://www.swift.org/package-manager/) is a tool for managing the distribution of Swift code. It’s integrated with the Swift build system to automate the process of downloading, compiling, and linking dependencies.

>Xcode 16.2+ is required to build the SeatGeekSDK using Swift Package Manager.

## Step I

To integrate SeatGeekSDK into your Xcode project using Swift Package Manager, add it to the dependencies value of your `Package.swift`:

    dependencies: [
        .package(url: "https://github.com/seatgeek/seatgeek-ios-sdk", from: "4.8.1")
    ]

SeatGeekSDK uses external dependencies. Here you can find a list of them along with versions. 

 - SnapKit '5.7.1'
 - SwiftOTP '3.0.0'
 - HTTPTypes '1.0.0'

SeatGeekSDK uses them as binary targets, so you won't see any of the external dependencies in your `Package.swift` description. 
>Your application can use these dependencies independently by importing them to your file. There is no need to add them separately.

## Step II
Next, you need to add SeatGeek authorisation credentials. Please reach out to your SeatGeek Enterprise client services representative to acquire it.
You will find a step-by-step plan on how to configure auth files in our documentation.

## Usage
- To get started with SeatGeekSDK please follow [this link](https://developer.seatgeek.com/docs/20afca50-1a5e-47f6-b80a-12fc5bc699b4/us-native-mobile-sdk) to our official documentation.
- Use our [demo repository](https://github.com/seatgeek/seatgeek-ios-sdk-demo) to see some basic examples of how to integrate the SDK into your app.
