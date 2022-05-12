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
            type: .dynamic,
            targets: ["SeatGeek"]),
    ],
    dependencies: [
        .package(url: "https://github.com/SnapKit/SnapKit.git", .upToNextMajor(from: "5.0.1")),
        .package(url: "https://github.com/dbarden/Charts.git", .upToNextMajor(from: "3.6.1")),
        .package(url: "https://github.com/dbarden/MarkdownKit.git", branch: "master"),
        .package(url: "https://github.com/dbarden/SwiftOTP.git", branch: "master")
    ],
    targets: [
        .binaryTarget(
            name: "SeatGeekSDK",
            url: "https://seatgeek.jfrog.io/artifactory/ios-sdk/v4.0.0/SeatGeekSDK.xcframework.zip",
            checksum: "fd5206cd9ea1dd6d0cd6bf13dc63985374e0a8731d20f58cf7dffd2710419257"
        ),
        .target(name: "SeatGeek",
                dependencies: [
                    .product(name: "SnapKit-Dynamic", package: "SnapKit"),
                    .product(name: "Charts-Dynamic", package: "Charts"),
                    .product(name: "MarkdownKit-Dynamic", package: "MarkdownKit"),
                    .product(name: "SwiftOTP-Dynamic",package: "SwiftOTP"),
                    .target(name: "SeatGeekSDK")
                ],
                path: "Sources/SeatGeekSDK/")
    ]
)
