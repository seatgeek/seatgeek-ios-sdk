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
            targets: ["_SeatGeekSDKTarget"]),
    ],
    dependencies: [
        .package(url: "https://github.com/apple/swift-http-types", exact: "1.2.0"),
        .package(url: "https://github.com/lachlanbell/SwiftOTP", exact: "3.0.0"),
        .package(url: "https://github.com/SnapKit/SnapKit", exact: "5.7.1")
    ],
    targets: [
        .target(
            name: "_SeatGeekSDKTarget",
            dependencies: [
                .target(name: "SeatGeekSDK"),
                .product(name: "HTTPTypes", package: "swift-http-types"),
                .product(name: "HTTPTypesFoundation", package: "swift-http-types"),
                .product(name: "SnapKit", package: "SnapKit"),
                .product(name: "SwiftOTP", package: "SwiftOTP")
            ]),
  
        .binaryTarget(
            name: "SeatGeekSDK",
            url: "https://seatgeek.jfrog.io/artifactory/sdk-ios/test-29-08/SeatGeekSDK.xcframework.zip",
            checksum: "c7d63333d216c69a08a527d2af544ea4c44add217cc0f001b4c6d2dcffc1e630"
        )
    ]
)
