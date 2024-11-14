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
            url: "https://seatgeek.jfrog.io/artifactory/sdk-ios/4.8.0/SeatGeekSDK.xcframework.zip",
            checksum: "1e3e2c2fa4252cafd5b9864f744a00da0898956a38783adc3889edd215741daa"
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
        ),
        .binaryTarget(
            name: "HTTPTypesFoundationTarget",
            url: "https://seatgeek.jfrog.io/artifactory/swift-http-types/swift-http-types-foundation.xcframework.zip",
            checksum: "f8ad38cdf7611b4868873f60a0cd08b3ce6980301755b98fd345a1a6e650123b"
        ),
        .binaryTarget(
            name: "HTTPTypesTarget",
            url: "https://seatgeek.jfrog.io/artifactory/swift-http-types/swift-http-types.xcframework.zip",
            checksum: "2c7677588c1e56bc83348a298333663d2430c33abb32fedaf36050848970d3dd"
        )
    ]
)
