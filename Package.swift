// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SeatGeek",
    platforms: [
        .iOS(.v15)
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
                "SwiftOTPTarget",
                "HTTPTypesFoundationTarget",
                "HTTPTypesTarget"
            ]
        ),
        .binaryTarget(
            name: "SeatGeekSDKTG",
            url: "https://seatgeek.jfrog.io/artifactory/sdk-ios/4.5.0/SeatGeekSDK.xcframework.zip",
            checksum: "ea47bc72f396256e7b7ead2f7d7c9a3f7a7ecd0f0a0947e9ec710dfa26c8aaf6"
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
            name: "HTTPTypesFoundationTarget",
            url: JFrogPath(forResourcePath: "/artifactory/swift-http-types/swift-http-types-foundation.xcframework.zip"),
            checksum: "f8ad38cdf7611b4868873f60a0cd08b3ce6980301755b98fd345a1a6e650123b"
        )
    ]
)
