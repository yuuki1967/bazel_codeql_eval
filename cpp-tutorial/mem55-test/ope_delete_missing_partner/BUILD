load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
COPTS = ["-DQNX_HOST=/home/yuki/work/bazel_codeql_eval/cpp-tutorial/target/qnx7", "-DQNX_TARGET=/home/yuki/work/bazel_codeql_eval/cpp-tutorial/qnx-sdp/target/qnx7"]

cc_binary(
    name = "test",
    copts = COPTS,
    srcs = ["test.cpp"],
)
