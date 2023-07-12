# MEM55
## Environment
OS: macos m1
bazel 6.2.1-homebrew
Apple clang version 14.0.3 (clang-1403.0.22.14.1)
Target: arm64-apple-darwin22.5.0
Thread model: posix

## How to analyze MEM55 with CodeQL

### automated (direct) operation

1. bazel clean --expunge
2. **codeql database create ../../../codeql-db/mem55-test -l cpp --command "bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test"**
3. **codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql**
```
$ bazel clean --expunge
INFO: Starting clean (this may take a while). Consider using --async if the clean takes more than several minutes.
yukiendo@YukinoMacBook-Pro: ~/workplace/examples/cpp-tutorial/mem55-test (main %=)
$ rm -rf ../../../codeql-db/mem55-test 
yukiendo@YukinoMacBook-Pro: ~/workplace/examples/cpp-tutorial/mem55-test (main %=)
$ codeql database create ../../../codeql-db/mem55-test -l cpp --command "bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test"
Initializing database at /Users/yukiendo/workplace/codeql-db/mem55-test.
Running build command: [bazel, build, --spawn_strategy=local, --nouse_action_cache, //ope_delete_missing_partner:test]
[2023-07-13 01:55:53] [build-stderr] Starting local Bazel server and connecting to it...
[2023-07-13 01:55:54] [build-stderr] Loading: 
[2023-07-13 01:55:55] [build-stderr] Loading: 
[2023-07-13 01:55:55] [build-stderr] Loading: 0 packages loaded
[2023-07-13 01:55:55] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (1 packages loaded, 0 targets configured)
[2023-07-13 01:55:56] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (28 packages loaded, 7 targets configured)
[2023-07-13 01:55:57] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (29 packages loaded, 7 targets configured)
[2023-07-13 01:56:10] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (29 packages loaded, 7 targets configured)
[2023-07-13 01:56:12] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:13] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:14] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:15] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:16] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:17] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:18] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:19] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:52] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-13 01:56:52] [build-stderr] INFO: Analyzed target //ope_delete_missing_partner:test (36 packages loaded, 161 targets configured).
[2023-07-13 01:56:52] [build-stderr] INFO: Found 1 target...
[2023-07-13 01:56:53] [build-stderr] [0 / 8] [Prepa] BazelWorkspaceStatusAction stable-status.txt ... ( 1 action running)
[2023-07-13 01:56:55] [build-stderr] [6 / 8] Compiling ope_delete_missing_partner/test.cpp; 1s local
[2023-07-13 01:56:56] [build-stderr] INFO: From Compiling ope_delete_missing_partner/test.cpp:
[2023-07-13 01:56:56] [build-stderr] ope_delete_missing_partner/test.cpp:10:6: warning: function previously declared with an explicit exception specification redeclared with an implicit exception specification [-Wimplicit-exception-spec-mismatch]
[2023-07-13 01:56:56] [build-stderr] void operator delete[](void *) {} // NON_COMPLIANT
[2023-07-13 01:56:56] [build-stderr]      ^
[2023-07-13 01:56:56] [build-stderr] /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/new:201:36: note: previous declaration is here
[2023-07-13 01:56:56] [build-stderr] _LIBCPP_OVERRIDABLE_FUNC_VIS void  operator delete[](void* __p) _NOEXCEPT;
[2023-07-13 01:56:56] [build-stderr]                                    ^
[2023-07-13 01:56:56] [build-stderr] ope_delete_missing_partner/test.cpp:13:6: warning: function previously declared with an explicit exception specification redeclared with an implicit exception specification [-Wimplicit-exception-spec-mismatch]
[2023-07-13 01:56:56] [build-stderr] void operator delete[](void *, const std::nothrow_t &) {} // COMPLIANT
[2023-07-13 01:56:56] [build-stderr]      ^
[2023-07-13 01:56:56] [build-stderr] /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/new:202:36: note: previous declaration is here
[2023-07-13 01:56:56] [build-stderr] _LIBCPP_OVERRIDABLE_FUNC_VIS void  operator delete[](void* __p, const std::nothrow_t&) _NOEXCEPT;
[2023-07-13 01:56:56] [build-stderr]                                    ^
[2023-07-13 01:56:56] [build-stderr] 2 warnings generated.
[2023-07-13 01:56:56] [build-stderr] [7 / 8] [Prepa] Linking ope_delete_missing_partner/test
[2023-07-13 01:56:57] [build-stderr] Target //ope_delete_missing_partner:test up-to-date:
[2023-07-13 01:56:57] [build-stderr]   bazel-bin/ope_delete_missing_partner/test
[2023-07-13 01:56:57] [build-stderr] INFO: Elapsed time: 64.424s, Critical Path: 3.71s
[2023-07-13 01:56:57] [build-stderr] INFO: 8 processes: 6 internal, 2 local.
[2023-07-13 01:56:57] [build-stderr] INFO: Build completed successfully, 8 total actions
Finalizing database at /Users/yukiendo/workplace/codeql-db/mem55-test.
Successfully created database at /Users/yukiendo/workplace/codeql-db/mem55-test.
$ codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql
Running queries.
Compiling query plan for /Users/yukiendo/workplace/bazel_codeql_eval/cpp-tutorial/mem55-test/../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
WARNING: Type XMLFile has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:19,35-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:28,37-47)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:39,51-61)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:47,32-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:55,32-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:63,31-41)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:146,31-41)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:162,11-21)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:168,11-21)
[1/1 comp 4s] Compiled /Users/yukiendo/workplace/bazel_codeql_eval/cpp-tutorial/mem55-test/../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
OperatorDeleteMissingPartnerCert.ql: [1/1 eval 399ms] Results written to cert-cpp-coding-standards/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.bqrs.
Shutting down query evaluator.
Interpreting results.
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
```
### indirect operation
1. bazel shutdown
2. bazel clean --expunge
3. **codeql database init ../../../codeql-db/mem55-test -l cpp -s .  **
4. **codeql database trace-command ../../../codeql-db/mem55-test -- bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test**
5. **codeql database finalize ../../../codeql-db/mem55-test **                                                                                                 
6. **codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql **
```
$ bazel shutdown
yukiendo@YukinoMacBook-Pro: ~/workplace/examples/cpp-tutorial/mem55-test (main %=)

$ bazel clean --expunge
INFO: Starting clean (this may take a while). Consider using --async if the clean takes more than several minutes.
yukiendo@YukinoMacBook-Pro: ~/workplace/examples/cpp-tutorial/mem55-test (main %=)

$ codeql database init ../../../codeql-db/mem55-test -l cpp -s .                                                                                          
Calculating baseline information in /Users/yukiendo/workplace/examples/cpp-tutorial/mem55-test
Calculated baseline information for languages: cpp (29ms).
Resolving extractor cpp.
Successfully loaded extractor C/C++ (cpp) from /Users/yukiendo/workplace/codeql/cpp.
Created skeleton CodeQL database at /Users/yukiendo/workplace/codeql-db/mem55-test. This in-progress database is ready to be populated by an extractor.
yukiendo@YukinoMacBook-Pro: ~/workplace/examples/cpp-tutorial/mem55-test (main %=)

$ codeql database trace-command ../../../codeql-db/mem55-test -- bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test
Running command in /Users/yukiendo/workplace/examples/cpp-tutorial/mem55-test: [bazel, build, --spawn_strategy=local, --nouse_action_cache, //ope_delete_missing_partner:test]
[2023-07-10 22:53:09] [build-stderr] Starting local Bazel server and connecting to it...
[2023-07-10 22:53:10] [build-stderr] Loading: 
[2023-07-10 22:53:11] [build-stderr] Loading: 
[2023-07-10 22:53:11] [build-stderr] Loading: 0 packages loaded
[2023-07-10 22:53:11] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (1 packages loaded, 0 targets configured)
[2023-07-10 22:53:12] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (28 packages loaded, 7 targets configured)
[2023-07-10 22:53:13] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (29 packages loaded, 7 targets configured)
[2023-07-10 22:53:26] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (29 packages loaded, 7 targets configured)
[2023-07-10 22:53:27] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:28] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:29] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:30] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:31] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:32] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:53:33] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:54:05] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-10 22:54:05] [build-stderr] INFO: Analyzed target //ope_delete_missing_partner:test (36 packages loaded, 161 targets configured).
[2023-07-10 22:54:05] [build-stderr] INFO: Found 1 target...
[2023-07-10 22:54:06] [build-stderr] [0 / 8] [Prepa] BazelWorkspaceStatusAction stable-status.txt ... ( 1 action running)
[2023-07-10 22:54:08] [build-stderr] [6 / 8] Compiling ope_delete_missing_partner/test.cpp; 1s local
[2023-07-10 22:54:09] [build-stderr] INFO: From Compiling ope_delete_missing_partner/test.cpp:
[2023-07-10 22:54:09] [build-stderr] ope_delete_missing_partner/test.cpp:10:6: warning: function previously declared with an explicit exception specification redeclared with an implicit exception specification [-Wimplicit-exception-spec-mismatch]
[2023-07-10 22:54:09] [build-stderr] void operator delete[](void *) {} // NON_COMPLIANT
[2023-07-10 22:54:09] [build-stderr]      ^
[2023-07-10 22:54:09] [build-stderr] /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/new:201:36: note: previous declaration is here
[2023-07-10 22:54:09] [build-stderr] _LIBCPP_OVERRIDABLE_FUNC_VIS void  operator delete[](void* __p) _NOEXCEPT;
[2023-07-10 22:54:09] [build-stderr]                                    ^
[2023-07-10 22:54:09] [build-stderr] ope_delete_missing_partner/test.cpp:13:6: warning: function previously declared with an explicit exception specification redeclared with an implicit exception specification [-Wimplicit-exception-spec-mismatch]
[2023-07-10 22:54:09] [build-stderr] void operator delete[](void *, const std::nothrow_t &) {} // COMPLIANT
[2023-07-10 22:54:09] [build-stderr]      ^
[2023-07-10 22:54:09] [build-stderr] /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/new:202:36: note: previous declaration is here
[2023-07-10 22:54:09] [build-stderr] _LIBCPP_OVERRIDABLE_FUNC_VIS void  operator delete[](void* __p, const std::nothrow_t&) _NOEXCEPT;
[2023-07-10 22:54:09] [build-stderr]                                    ^
[2023-07-10 22:54:09] [build-stderr] 2 warnings generated.
[2023-07-10 22:54:09] [build-stderr] [7 / 8] [Prepa] Linking ope_delete_missing_partner/test
[2023-07-10 22:54:09] [build-stderr] Target //ope_delete_missing_partner:test up-to-date:
[2023-07-10 22:54:09] [build-stderr]   bazel-bin/ope_delete_missing_partner/test
[2023-07-10 22:54:09] [build-stderr] INFO: Elapsed time: 60.251s, Critical Path: 3.36s
[2023-07-10 22:54:09] [build-stderr] INFO: 8 processes: 6 internal, 2 local.
[2023-07-10 22:54:09] [build-stderr] INFO: Build completed successfully, 8 total actions

$ codeql database finalize ../../../codeql-db/mem55-test                                                                                                  
Running TRAP import for CodeQL database at /Users/yukiendo/workplace/codeql-db/mem55-test...
TRAP import complete (892ms).

$ codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql
Running queries.
Compiling query plan for /Users/yukiendo/workplace/bazel_codeql_eval/cpp-tutorial/mem55-test/../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
WARNING: Type XMLFile has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:19,35-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:28,37-47)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:39,51-61)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:47,32-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:55,32-42)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:63,31-41)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:146,31-41)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:162,11-21)
WARNING: Type XMLElement has been deprecated and may be removed in future (/Users/yukiendo/workplace/vscode-codeql-starter/codeql-coding-standards/cpp/common/src/codingstandards/cpp/deviations/Deviations.qll:168,11-21)
[1/1 comp 4s] Compiled /Users/yukiendo/workplace/bazel_codeql_eval/cpp-tutorial/mem55-test/../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
OperatorDeleteMissingPartnerCert.ql: [1/1 eval 399ms] Results written to cert-cpp-coding-standards/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.bqrs.
Shutting down query evaluator.
Interpreting results.
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
Error retrieving qlpack commit hash from Git repository
```

