load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "test-diff",
    srcs = ["test-diff.cpp"],
    hdrs = ["test-diff.h", "test.h"],
)

cc_binary(
    name = "test",
    srcs = ["test.cpp"],
    deps = [
        ":test-diff",
    ],
)
