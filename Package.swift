// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SeatGeek",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "SeatGeek",
            targets: ["_SeatGeekSDKTarget"])
    ],
    targets: [
        .target(
            name: "_SeatGeekSDKTarget",
            dependencies: [.target(name: "_SeatGeekSDKWrapper",
                                   condition: .when(platforms: [.iOS]))]
        ),
        .target(
            name: "_SeatGeekSDKWrapper",
            dependencies: [
                "SeatGeekSDKTG",
                "SnapKitTarget",
                "MarkdownKitTarget",
                "SwiftOTPTarget"
            ]
        ),
        .binaryTarget(
            name: "SeatGeekSDKTG",
            url: "https://seatgeek.jfrog.io/artifactory/sdk-ios/4.3.0/SeatGeekSDK.xcframework.zip",
            checksum: "6c490e1121f22a303414177c0f914475d528b7c19244f6cd424630e591556821"
        ),
        .binaryTarget(
            name: "SnapKitTarget",
            url: "https://seatgeek.jfrog.io/artifactory/snapkit-ios/v5.6.0/SnapKit.xcframework.zip",
            checksum: "dcd611ca6013f7e68fb6ec0da55962c03ae3928dcf81508dae66303f7d429e7d"
        ),
        .binaryTarget(
            name: "SwiftOTPTarget",
            url: "https://seatgeek.jfrog.io/artifactory/swiftotp-ios/v3.0.0/SwiftOTP.xcframework.zip",
            checksum: "94bd56c16c25346e4eb490090ed2a63717b4d60eb6bed7b1493acdd0b11081e7"
        ),
        .binaryTarget(
            name: "MarkdownKitTarget",
            url: "https://seatgeek.jfrog.io/artifactory/markdownkit-ios/v1.7.0/MarkdownKit.xcframework.zip",
            checksum: "ff216b422c0136381ca070190e4c57adef3b3ca78e0d5b6d467aeeb982f6b108"
        )
    ]
)
