// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SeatGeek",
    platforms: [
        .iOS(.v16)
    ],
    products: [
        .library(
            name: "SeatGeek",
            targets: ["_SeatGeekSDKTarget"])
    ],
    // dependencies: [
    //     .package(url: "https://github.com/apple/swift-http-types", from: "1.2.0", moduleAliases: ["HTTPTypes": "SGSDKHTTPTypes"]),
    // ],
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
                "SwiftOTPTarget"
                // .product(name: "HTTPTypes", package: "swift-http-types"),
                // .product(name: "HTTPTypesFoundation", package: "swift-http-types")
            ]
        ),
        .binaryTarget(
            name: "SeatGeekSDKTG",
            url: "https://seatgeek.jfrog.io/artifactory/sdk-ios/debug/5.2.0/SeatGeekSDK-120226.xcframework.zip",
            checksum: "ade699858cde956e9eae4037a4255494bbe85e41eeef68d79da14ed171f3b1c8"
        ),
        .binaryTarget(
            name: "SnapKitTarget",
            url: "https://seatgeek.jfrog.io/artifactory/snapkit-ios/v5.7.1/SnapKit-signed.xcframework.zip",
            checksum: "0a9acdae73aa612b685f704a49a0aaae11c8770e08f0c9e9954342bf9ed30fd8"
        ),
        .binaryTarget(
            name: "SwiftOTPTarget",
            url: "https://seatgeek.jfrog.io/artifactory/swiftotp-ios/v3.0.0/SwiftOTP.xcframework.zip",
            checksum: "94bd56c16c25346e4eb490090ed2a63717b4d60eb6bed7b1493acdd0b11081e7"
        )
    ]
)
