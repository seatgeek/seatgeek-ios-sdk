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
            targets: ["SeatGeek"]),
    ],
    dependencies: [
        .package(url: "https://github.com/SnapKit/SnapKit.git", .upToNextMajor(from: "5.0.1")),
        .package(url: "https://github.com/danielgindi/Charts.git", .upToNextMajor(from: "3.4.0")),
        .package(url: "https://github.com/bmoliveira/MarkdownKit.git", from: "1.7.0"),
        .package(url: "https://github.com/lachlanbell/SwiftOTP.git", .upToNextMinor(from: "3.0.0"))
    ],
    targets: [
        .binaryTarget(
            name: "SeatGeekSDK",
            url: "https://seatgeek.jfrog.io/artifactory/ios-sdk/v4.0.0/SeatGeekSDK.xcframework.zip",
            checksum: "765813de02a4e3b9abcfd27d9177f3eb3d3c992135d99ecf1b4971d339a8400a"
        ),
        .target(name: "SeatGeek",
                dependencies: [
                    "SnapKit", "Charts", "MarkdownKit", "SwiftOTP",
                    .target(name: "SeatGeekSDK")
                ],
                path: "Sources/SeatGeekSDK/")
    ]
)
