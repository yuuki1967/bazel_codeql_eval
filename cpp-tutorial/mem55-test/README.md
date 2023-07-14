# MEM55
## Environment
Ubuntu
bazel 6.2.1
qcc

## How to analyze MEM55 with CodeQL

### automated (direct) operation
0. bazel shutdown
1. bazel clean --expunge
2. **codeql database create ../../../codeql-db/mem55-test -l cpp --command "bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test"**
3. **codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql**
```
$ bazel clean --expunge
$ codeql database create ../../../codeql-db/bazel_mem55_test/ -l cpp --command="bazel build //ope_delete_missing_partner:test --spawn_strategy=local --nouse_action_cache" --overwrite
Initializing database at /home/yuki/work/codeql-db/bazel_mem55_test.
Running build command: [bazel, build, //ope_delete_missing_partner:test, --spawn_strategy=local, --nouse_action_cache]
[2023-07-14 15:12:05] [build-stderr] Starting local Bazel server and connecting to it...
[2023-07-14 15:12:05] [build-stderr] WARNING: ignoring LD_PRELOAD in environment.
[2023-07-14 15:12:07] [build-stderr] Loading: 
[2023-07-14 15:12:08] [build-stderr] Loading: 
[2023-07-14 15:12:08] [build-stderr] Loading: 0 packages loaded
[2023-07-14 15:12:08] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (1 packages loaded, 0 targets configured)
[2023-07-14 15:12:09] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (30 packages loaded, 109 targets configured)
[2023-07-14 15:12:11] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (32 packages loaded, 125 targets configured)
[2023-07-14 15:12:12] [build-stderr] Analyzing: target //ope_delete_missing_partner:test (36 packages loaded, 157 targets configured)
[2023-07-14 15:12:12] [build-stderr] INFO: Analyzed target //ope_delete_missing_partner:test (36 packages loaded, 157 targets configured).
[2023-07-14 15:12:12] [build-stderr] INFO: Found 1 target...
[2023-07-14 15:12:12] [build-stderr] [0 / 6] [Scann] Compiling ope_delete_missing_partner/test.cpp
[2023-07-14 15:12:13] [build-stderr] Target //ope_delete_missing_partner:test up-to-date:
[2023-07-14 15:12:13] [build-stderr]   bazel-bin/ope_delete_missing_partner/test
[2023-07-14 15:12:13] [build-stderr] INFO: Elapsed time: 7.310s, Critical Path: 0.38s
[2023-07-14 15:12:13] [build-stderr] INFO: 6 processes: 4 internal, 2 local.
[2023-07-14 15:12:13] [build-stderr] INFO: Build completed successfully, 6 total actions
Finalizing database at /home/yuki/work/codeql-db/bazel_mem55_test.
Successfully created database at /home/yuki/work/codeql-db/bazel_mem55_test.
$ codeql database analyze ../../../codeql-db/bazel_mem55_test/ --format=sarif-latest --output=results.sarif ~/work/vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql
Running queries.
Compiling query plan for /home/yuki/work/vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
[1/1] Found in cache: /home/yuki/work/vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql.
OperatorDeleteMissingPartnerCert.ql: [1/1 eval 1.7s] Results written to codeql/
Shutting down query evaluator.
Interpreting results.

```
### indirect operation
1. bazel shutdown
2. bazel clean --expunge
3. **codeql database init ../../../codeql-db/mem55-test -l cpp -s .  **
4. **codeql database trace-command ../../../codeql-db/mem55-test -- bazel build --spawn_strategy=local --nouse_action_cache //ope_delete_missing_partner:test**
5. **codeql database finalize ../../../codeql-db/mem55-test **                                                                                                 
6. **codeql database analyze ../../../codeql-db/mem55-test  --format=sarif-latest --output=results.sarif ../../../vscode-codeql-starter/codeql-coding-standards/cpp/cert/src/rules/MEM55-CPP/OperatorDeleteMissingPartnerCert.ql **
