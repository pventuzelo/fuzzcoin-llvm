//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// fuzzer::FuzzingOptions
//===----------------------------------------------------------------------===//

#ifndef LLVM_FUZZER_OPTIONS_H
#define LLVM_FUZZER_OPTIONS_H

#include "FuzzerDefs.h"

namespace fuzzer {

struct FuzzingOptions {
  int Verbosity = 1;
  size_t MaxLen = 0;
  size_t LenControl = 1000;
  int UnitTimeoutSec = 300;
  int TimeoutExitCode = 70;
  int OOMExitCode = 71;
  int InterruptExitCode = 72;
  int ErrorExitCode = 77;
  bool IgnoreTimeouts = true;
  bool IgnoreOOMs = true;
  bool IgnoreCrashes = false;
  int MaxTotalTimeSec = 0;
  int RssLimitMb = 0;
  int MallocLimitMb = 0;
  bool DoCrossOver = true;
  int MutateDepth = 5;
  bool ReduceDepth = false;
  bool UseCounters = false;
  bool UseMemmem = true;
  bool UseCmp = false;
  int UseValueProfile = false;
  bool Shrink = false;
  bool ReduceInputs = false;
  int ReloadIntervalSec = 1;
  bool ShuffleAtStartUp = true;
  bool PreferSmall = true;
  size_t MaxNumberOfRuns = -1L;
  int ReportSlowUnits = 10;
  bool OnlyASCII = false;
  std::string OutputCorpus;
  std::string ArtifactPrefix = "./";
  std::string ExactArtifactPath;
  std::string ExitOnSrcPos;
  std::string ExitOnItem;
  std::string FocusFunction;
  std::string DataFlowTrace;
  std::string CollectDataFlow;
  std::string FeaturesDir;
  std::string StopFile;

  //{{ added for fuzzcoin
  std::string CurrentInputPath = ".cur_input";  // same as AFL
  std::string CurrentCoverageDir = "features";  // tmp dir to dump out the feature as we want
  std::string CheckerScriptPath = "./checker.py"; // coverage expansion checker
  std::string PofwPath = "pofw";
  std::string LogPath = ".cur_runs";
  unsigned int PofwSlowdownThreashHold = 10000; // calculate PoFW for this amount of initial iteration
  unsigned int PofwSlowdownRate = 10;	  	// calculates PoFW once this iteration
  unsigned pofw_seed = 0;			// initialize this from FuzzDriver.cpp, then use it for PoFW
  //}}

  bool SaveArtifacts = true;
  bool PrintNEW = true; // Print a status line when new units are found;
  bool PrintNewCovPcs = false;
  int PrintNewCovFuncs = 0;
  bool PrintFinalStats = false;
  bool PrintCorpusStats = false;
  bool PrintCoverage = false;
  bool DumpCoverage = false;
  bool DetectLeaks = true;
  int PurgeAllocatorIntervalSec = 1;
  int  TraceMalloc = 0;
  bool HandleAbrt = false;
  bool HandleBus = false;
  bool HandleFpe = false;
  bool HandleIll = false;
  bool HandleInt = false;
  bool HandleSegv = false;
  bool HandleTerm = false;
  bool HandleXfsz = false;
  bool HandleUsr1 = false;
  bool HandleUsr2 = false;
};

}  // namespace fuzzer

#endif  // LLVM_FUZZER_OPTIONS_H
