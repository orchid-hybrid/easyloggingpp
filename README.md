![banner]

                                       ﻿بِسمِ اللہِ الرَّحمٰنِ الرَّحِيم

> **Manual For v9.24**
>
> [![Build Status](https://travis-ci.org/easylogging/easyloggingpp.png?branch=develop)](https://travis-ci.org/easylogging/easyloggingpp)

### Quick Links

  [![download] Download Latest](http://easylogging.org/latest.zip)
  
  [![notes] Release Notes](https://github.com/easylogging/easyloggingpp/tree/master/doc/RELEASE-NOTES-v9.24)
 
  [![samples] Samples](https://github.com/easylogging/easyloggingpp/tree/master/samples/)
  
  [![www] Project Homepage](http://easylogging.org/)

  [![pledgie]](http://www.pledgie.com/campaigns/22070)


---

### Table of Contents
<pre>
<a href="#introduction">Introduction</a>
    <a href="#why-yet-another-library">Why yet another library</a>
    <a href="#features-at-a-glance">Features at a glance</a>
    <a href="#whats-new">What's new?</a>
<a href="#getting-started">Getting Started</a>
    <a href="#download">Download</a>
    <a href="#quick-start">Quick Start</a>
    <a href="#setting-application-arguments">Setting Application Arguments</a>
<a href="#configuration">Configuration</a>
    <a href="#level">Level</a>
    <a href="#configure">Configure</a>
        <a href="#using-configuration-file">Using Configuration File</a>
        <a href="#using-elconfigurations-class">Using el::Configurations Class</a>
        <a href="#using-in-line-configurations">Using In line Configurations</a>
    <a href="#default-configurations">Default Configurations</a>
    <a href="#global-configurations">Global Configurations</a>
    <a href="#logging-format-specifiers">Logging Format Specifiers</a>
    <a href="#datetime-format-specifiers">Date/Time Format Specifiers</a>
    <a href="#logging-flags">Logging flags</a>
    <a href="#application-arguments">Application Arguments</a>
    <a href="#configuration-macros">Configuration Macros</a>
    <a href="#reading-configurations">Reading Configurations</a>
<a href="#logging">Logging</a>
    <a href="#basic">Basic</a>
    <a href="#conditional-logging">Conditional Logging</a>
    <a href="#occasional-logging">Occasional Logging</a>
    <a href="#verbose-logging">Verbose Logging</a>
        <a href="#basic-1">Basic</a>
        <a href="#conditional-and-occasional">Conditional and Occasional</a>
        <a href="#verbose-level">Verbose Level</a>
        <a href="#check-if-verbose-logging-is-on">Check If Verbose Logging Is On</a>
        <a href="#vmodule">VModule</a>
    <a href="#stl-logging">STL Logging</a>
        <a href="#supported-templates">Supported Templates</a>
    <a href="#registering-new-loggers">Registering New Loggers</a>
    <a href="#populating-existing-logger-ids">Populating Existing Logger IDs</a>
<a href="#extra-features">Extra Features</a>
    <a href="#performance-tracking">Performance Tracking</a>
    <a href="#log-file-rolling">Log File Rolling</a>
    <a href="#crash-handling">Crash Handling</a>
        <a href="#installing-custom-crash-handlers">Installing Custom Crash Handlers</a>
    <a href="#stacktrace">Stacktrace</a>
    <a href="#multi-threading">Multi-threading</a>
    <a href="#check-macros">CHECK Macros</a>
    <a href="#logging-perror">Logging perror()</a>
    <a href="#syslog">Using Syslog</a>
    <a href="#qt-logging">Qt Logging</a>
    <a href="#boost-logging">Boost Logging</a>
    <a href="#wxwidgets-logging">wxWidgets Logging</a>
    <a href="#extending-library">Extending Library</a>
        <a href="#logging-your-own-class">Logging Your Own Class</a>
        <a href="#logging-third-party-class">Logging Third-party Class</a>
    <a href="#manually-flushing-and-rolling-log-files">Manually Flushing and Rolling Log Files</a>
<a href="#contribution">Contribution</a>
    <a href="#submitting-patches">Submitting Patches</a>
    <a href="#reporting-a-bug">Reporting a Bug</a>
    <a href="#donation">Donation</a>
<a href="#compatibility">Compatibility</a>
<a href="#licence">Licence</a>
<a href="#disclaimer">Disclaimer</a>
</pre>

# Introduction
Easylogging++ is single header only, feature-rich, efficient logging library for C++ applications. It has been written keeping three things in mind; performance, management (setup, configure, log, simple) and portability. Its highly configurable and extremely useful for small to large size projects.
This manual is written as starting reference for version 9.0+. For older versions please refer to corresponding [releases](https://github.com/easylogging/easyloggingpp/releases) on github.

 [![top] Goto Top](#table-of-contents)
 
### Why yet another library
If you are working on a small utility or large project in C++, this library can be handy. Its based on single header and does not require linking or installation. You can import into your project as if its part of your project. This library has been designed with various thoughts and performance and usability problems and improvements in mind. Code has been managed in such a way that everything (or most) is accessible within header itself.

Why yet another library? Well, answer is pretty straight forward, use it as if you wrote it so you can fix issues (if any) as you go or raise them on github. In addition to that, I have not seen any logging library based on single-header with such a design where you can configure on the go and get the same performance. I have seen other single-header logging libraries for C++ but either they use external libraries, e.g, boost, Qt to support certain features like threading, regular expression or date etc. This library has everything built-in to prevent usage of external libraries, not that I don't like those libraries, in fact I love them, but because not all projects use these libraries, I couldn't take risk of depending on them.

 [![top] Goto Top](#table-of-contents)
 
### Features at a glance
Easylogging++ is feature-rich containing many features that a typical developer will require while writing a software;
 * Highly configurable
 * Extremely fast
 * Thread and type safe
 * Cross-platform
 * Custom log patterns
 * Conditional and occasional logging
 * Performance tracking
 * Verbose logging
 * Crash handling
 * Helper CHECK macros
 * STL logging
 * Third-party library logging (Qt, boost, wxWidgets etc)
 * Extensible (Logging your own class or third-party class)
 * And many more...

 [![top] Goto Top](#table-of-contents)

### What's new?
Easylogging++ 9.0 has been changed a lot from the first version and even from its previous major version, v8.x. Major changes were to improve performance and provide more features. v9.0 makes extensive use of C++11 features and is only supported by  C++11 compliant compilers that support strongly-typed enums, nullptr, lambda expressions, move semantics, smart pointers (unique_ptr and shared_ptr). std::thread is optional and can be suppressed either in favour of using wrappers or disabling threading support completely (disabled by default); in case of wrappers, *nix systems use pthreads and windows use CriticalSection from windows.h header.
Applications that do not use C++11 may still use v8.x which is also efficient provided you have a look at issue 66 on github. This version also lack support for following features that were introduced post v8.x;
* Log date/time patterns
* Crash handling
* Stacktrace on failures
* Helper CHECK macros
* Third-party library logging (except for Qt)

Please note, most of the features can be disabled by defining macros. Details are given later in this manual. As far as upgrade from v8.x is concerned, you can refer to release notes on github to see what's deprecated and what's changed.

 [![top] Goto Top](#table-of-contents)
 
# Getting Started
### Download
Current stable release is always http://easylogging.org/latest.zip

Versioned releases can be downloaded from `http://easylogging.org/releases/easyloggingpp_v[MAJOR].[MINOR].zip` for example for v8.91, link will be `http://easylogging.org/releases/easyloggingpp_v8.91.zip` and corresponding release notes are `http://easylogging.org/releases/release-notes-v[MAJOR].[MINOR].txt`

Minimum downloadable version is version 8.91 and minimum version with release notes is version 9.00. If you wish to get an older version (up to v2.3) please email support@easylogging.org with your reason of using older version. Using older versions are not recommended as there were some minor and major fixes with every version to improve performance.

 [![top] Goto Top](#table-of-contents)
 
### Quick Start
In order to get started with Easylogging++, you can follow three easy steps;
* Download latest header
* Include into your project
* Initialize using single macro... and off you go!

```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(int argv, char* argc[]) {
   LOG(INFO) << "My first info log using default logger";
   return 0;
}
```

That simple! Please note that `_INITIALIZE_EASYLOGGINGPP` should be used once and once-only otherwise you will end up getting compilation errors. What this is actually, its an extern variable definition. This means it can be defined only once per application. Best place to put this initialization statement is in file where main function is defined, right after last include statement.

 [![top] Goto Top](#table-of-contents)
 
### Setting Application Arguments
Some features of Easylogging++ require you to set application arguments, e.g, verbose logging to set verbose level or vmodules (explained later). In order to do that you can use helper macro or helper class;

```c++
int main(int argv, char* argc[]) {
   _START_EASYLOGGINGPP(argc, argv);
   ...
}
// -- OR --
int main(int argv, char* argc[]) {
   el::Helpers::setArgs(argc, argv);
   ...
}
```
 [![top] Goto Top](#table-of-contents)
 
# Configuration
### Level
In order to start configuring your logging library, you must understand severity levels. Easylogging++ deliberately does not use hierarchical logging in order to fully control what's enabled and what's not. Developers may enable/disable any level regardless of what level is it. Easylogging++ has following levels

|   Level  |                 Description                                                                                                                                   |
|----------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Global   | Generic level that represents all levels. Useful when setting global configuration for all levels.                                                            |
| Debug    | Informational events most useful for developers to debug application. Only applicable if NDEBUG is not defined (for non-VC++) or _DEBUG is defined (for VC++).|
| Info     | Mainly useful to represent current progress of application.                                                                                                   |
| Warning  | Information representing errors in application but application will keep running.                                                                             |
| Error    | Error information but will continue application to keep running.                                                                                              |
| Fatal    | Very severe error event that will presumably lead the application to abort.                                                                                   |
| Verbose  | Information that can be highly useful and vary with verbose logging level.                                                                                    |
| Trace    | Information that can be useful to back-trace certain events - mostly useful than debug logs.                                                                  |

 [![top] Goto Top](#table-of-contents)
 
### Configure
Easylogging++ is easy to configure. There are three possible ways to do so,
* Using configuration file
* Using el::Configurations class
* Using inline configuration

#### Using Configuration File
Configuration can be done by file that is loaded at runtime by Configurations class. This file has following format;
```
* LEVEL:
  CONFIGURATION NAME  = "VALUE" ## Comment
  ANOTHER CONFIG NAME = "VALUE"
```

Level name starts with a star (*) and ends with colon (:). It is highly recommended to start your configuration file with GLOBAL level so that any configuration not specified in the file will automatically use configuration from GLOBAL. For example, if you set FILENAME in GLOBAL and you want all the levels to use same filename, do not set it explicitly for each level, API will use value from GLOBAL automatically.
Following table contains configurations supported by configuration file.

|   Configuration Name  |   Type   |                 Description                                                                                                                                                 |
|-----------------------|----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Enabled               |   bool   | Determines whether or not corresponding level for logger is enabled. You may disable all logs by using el::Level::Global                                                    |
| To_File               |   bool   | Whether or not to write corresponding log to log file                                                                                                                       |
| To_Standard_Output    |   bool   | Whether or not to write logs to standard output e.g, terminal or command prompt                                                                                             |
| Format                |   char*  | Determines format/pattern of logging for corresponding level and logger.                                                                                                    |
| Filename              |   char*  | Determines log file (full path) to write logs to for corresponding level and logger                                                                                         |
| Milliseconds_Width    |   uint   | Specifies milliseconds width. Width can be within range (1-6)                                                                                                               |
| Performance_Tracking  |   bool   | Determines whether or not performance tracking is enabled. This does not depend on logger or level. Performance tracking always uses 'performance' logger unless specified. |
| Max_Log_File_Size     |   size_t | If log file size of corresponding level is >= specified size, log file will be truncated.                                                                                   |
| Log_Flush_Threshold   |  size_t  | Specifies number of log entries to hold until we flush pending log data |
	

Please do not use double-quotes anywhere in comment, you might end up in unexpected behaviour.

Sample Configuration File
```
* GLOBAL:
   FORMAT               =  "%datetime %msg"
   FILENAME             =  "/tmp/logs/my.log"
   ENABLED              =  true
   TO_FILE              =  true
   TO_STANDARD_OUTPUT   =  true
   MILLISECONDS_WIDTH   =  6
   PERFORMANCE_TRACKING =  true
   MAX_LOG_FILE_SIZE    =  2097152 ## 2MB - Comment starts with two hashes (##)
   LOG_FLUSH_THRESHOLD  =  100 ## Flush after every 100 logs
* DEBUG:
   FORMAT               = "%datetime{%d/%M} %func %msg"
```

##### Explanation 
Configuration file contents in above sample is straightforward. We start with `GLOBAL` level in order to override all the levels. Any explicitly defined subsequent level will override configuration from `GLOBAL` for that level. For example, all the levels except for `DEBUG` have the same format, i.e, datetime and log message. For `DEBUG` level, we have only date (with day and month), logging function and log message. The rest of configurations for DEBUG are used from GLOBAL. Also, notice {%d/%M} in DEBUG format above, if you do not specify date format, default format is used. Default values of date/time is `%d/%M/%Y %h:%m:%s,%g` For more information on these format specifiers, please refer to Date/Time Format Specifier section below

##### Usage
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
    // Load configuration from file
    el::Configurations conf("my-conf.conf");
    // Reconfigure single logger
    el::Loggers::reconfigureLogger("default", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);
    // Now all the loggers will use configuration from file
}
```

 [![top] Goto Top](#table-of-contents)
 
#### Using el::Configurations Class
You can set configurations or reset configurations;
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

int main(int argc, const char** argv) {
   el::Configurations defaultConf;
   defaultConf.setToDefault();
    // Values are always std::string
   defaultConf.set(el::Level::Info, 
            el::ConfigurationType::Format, "%datetime %level %msg");
    // default logger uses default configurations
    el::Loggers::reconfigureLogger("default", defaultConf);
    LOG(INFO) << "Log using default file";
    // To set GLOBAL configurations you may use
   defaultConf.setGlobally(
            el::ConfigurationType::Format, "%date %msg");
   el::Loggers::reconfigureLogger("default", defaultConf);
    return 0;
}
```

Configuration just needs to be set once. If you are happy with default configuration, you may use it as well.

 [![top] Goto Top](#table-of-contents)
 
#### Using In line Configurations
Inline configuration means you can set configurations in std::string but make sure you add all the new line characters etc.
```c++
el::Configurations c;
c.setToDefault();
c.parseFromText("*GLOBAL:\n FORMAT = %level %msg");
```

Please note, above code only sets Configurations object, you still need to re-configure logger/s using this configurations.

 [![top] Goto Top](#table-of-contents)
 
### Default Configurations
If you wish to have a configuration for existing and future loggers, you can use `el::Loggers::setDefaultConfigurations(el::Configurations& configurations, bool configureExistingLoggers = false)`. This is useful when you are working on fairly large scale, or using a third-party library that is already using Easylogging++. Any newly created logger will use default configurations. If you wish to configure existing loggers as well, you can set second argument to `true` (it defaults to `false`).

 [![top] Goto Top](#table-of-contents)
 
### Global Configurations
`Level::Global` is nothing to do with global configurations, it is concept where you can register configurations for all/or some loggers and even register new loggers using configuration file. Syntax of configuration file is:
```
-- LOGGER ID ## Case sensitive
  ## Everything else is same as configuration file


-- ANOTHER LOGGER ID
  ## Configuration for this logger
```

Logger ID starts with two dashes. Once you have written your global configuration file you can configure your all loggers (and register new ones) using single function;
```c++
int main(void) {
   // Registers new and configures it or
   // configures existing logger - everything in global.conf
   el::Loggers::configureFromGlobal("global.conf");
   // .. Your prog
   return 0;
}
```
Please note, it is not possible to register new logger using global configuration without defining its configuration. You must define at least single configuration. Other ways to register loggers are discussed in Logging section below.

 [![top] Goto Top](#table-of-contents)
 
### Logging Format Specifiers
You can customize format of logging using following specifiers:

|     Specifier   |                 Replaced By                                                                 |
|-----------------|---------------------------------------------------------------------------------------------|
| `%logger`       | Logger ID                                                                                   |
| `%thread`       | Thread ID - Uses std::thread if available, otherwise GetCurrentThreadId() on windows        |
| `%level`        | Severity level (Info, Debug, Error, Warning, Fatal, Verbose, Trace)                         |
| `%vlevel`       | Verbosity level (Applicable to verbose logging)                                             |
| `%datetime`     | Date and/or time - Pattern is customizable - see Date/Time Format Specifiers below          |
| `%user`         | User currently running application                                                          |
| `%host`         | Computer name application is running on                                                     |
| `%func`         | Logging function                                                                            |
| `%loc`          | Source filename and line number of logging                                                  |
| `%msg`          | Actual log message, (before ver.9.25 it was `%log`)                                         |
| `%`             | Escape character (e.g, %%level will write %level)                                           |

Since ver. 9.23, you can also specify your own format specifiers. In order to do that you can use `el::Helpers::installCustomFormatSpecifier`. A perfect example is `%ip_addr` for TCp server application;

```C++
const char* getIp(void) {
    return "192.168.1.1";
}

int main(void) {
    el::Helpers::installCustomFormatSpecifier(el::CustomFormatSpecifier("%ip_addr", getIp));
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime %level %ip_addr : %msg");
    LOG(INFO) << "This is request from client";
    return 0;
}
```

 [![top] Goto Top](#table-of-contents)
 
### Date/Time Format Specifiers
You can customize date/time format using following specifiers

|    Specifier    |                 Replaced By                                                                                      |
|-----------------|------------------------------------------------------------------------------------------------------------------|
| `%d`            | Day of month (zero-padded)                                                                                       |
| `%a`            | Day of the week - short (Mon, Tue, Wed, Thu, Fri, Sat, Sun)                                                      |
| `%A`            | Day of the week - long (Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday)                          |
| `%M`            | Month (zero-padded)                                                                                              |
| `%b`            | Month - short (Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec)                                       |
| `%B`            | Month - Long (January, February, March, April, May, June, July, August, September, October, November, December)  |
| `%y`            | Year - Two digit (13, 14 etc)                                                                                    |
| `%Y`            | Year - Four digit (2013, 2014 etc)                                                                               |
| `%h`            | Hour (12-hour format)                                                                                            |
| `%H`            | Hour (24-hour format)                                                                                            |
| `%m`            | Minute (zero-padded)                                                                                             |
| `%s`            | Second (zero-padded)                                                                                             |
| `%g`            | Milliseconds (width is configured by ConfigurationType::MillisecondsWidth)                                       |
| `%F`            | AM/PM designation                                                                                                |
| `%`             | Escape character                                                                                                 |

Please note, date/time is limited to `30` characters at most.

 [![top] Goto Top](#table-of-contents)
 
###Logging flags
Form some parts of logging you can set logging flags; here are flags supported:

|     Flag                                 |                 Description                                                                                                                   |
|------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| `NewLineForContainer (1)`                | Makes sure we have new line for each container log entry                                                                                      |
| `AllowVerboseIfModuleNotSpecified (2)`   | Makes sure if -vmodule is used and does not specifies a module, then verbose logging is allowed via that module. Say param was -vmodule=main*=3 and a verbose log is being written from a file called something.cpp then if this flag is enabled, log will be written otherwise it will be disallowed. Note: having this defeats purpose of -vmodule                                 |
| `LogDetailedCrashReason (4)`         | When handling crashes by default, detailed crash reason will be logged as well (Disabled by default) ([issue #90](https://github.com/easylogging/easyloggingpp/issues/90))                                                                                                                                                                                |
| `DisableApplicationAbortOnFatalLog (8)`  | Allows to disable application abortion when logged using FATAL level. Note that this does not apply to default crash handlers as application should be aborted after crash signal is handled. (Not added by default) ([issue #119](https://github.com/easylogging/easyloggingpp/issues/119))                                                                                                                                                                               |
| `ImmediateFlush (16)`                    | Flushes log with every log-entry (performance sensative) - Disabled by default                                                                |
| `StrictLogFileSizeCheck (32)`            | Makes sure log file size is checked with every log                                                                                            |

You can set/unset these flags by using static `el::Helpers::addFlag` and `el::Helpers::removeFlag`. You can check to see if certain flag is available by using `el::Helpers::hasFlag`, all these functions take strongly-typed enum `el::LoggingFlag`

 > Since ver. 9.25, you can set these flags by using `--logging-flags` command line arg. If you wish to force to disable this functionality define `_ELPP_DISABLE_LOGGING_FLAGS_FROM_ARG` (You will need to make sure to use `_START_EASYLOGGINGPP(argc, argv)` to configure arguments).

 [![top] Goto Top](#table-of-contents)

### Application Arguments
Following table will explain all command line arguments that you may use to define certain behaviour; You will need to initialize application arguments by using `_START_EASYLOGGINGPP(argc, argv)` in your `main(int, char**)` function.

|        Argument            |                                      Description                                        |
|----------------------------|-----------------------------------------------------------------------------------------|
| `-v`                       | Activates maximum verbosity                                                             |
| `--v=2`                    | Activates verbosity upto verbose level 2 (valid range: 0-9)                             |
| `--verbose`                | Activates maximum verbosity                                                             |
| `-vmodule=MODULE_NAME`     | Activates verbosity for files starting with main to level 1, the rest of the files depend on logging flag `AllowVerboseIfModuleNotSpecified` Please see Logging Flags section above. Two modules can be separated by comma. Please note vmodules are last in order of precedence of checking arguments for verbose logging, e.g, if we have -v in application arguments before vmodules, vmodules will be ignored.                                                                                                               |
| `--logging-flags=3`        | Since ver. 9.25, Sets logging flag. In example `i.e, 3`, it sets logging flag to `NewLineForContainer` and `AllowVerboseIfModuleNotSpecified`. See logging flags section above for further details and values. See macros section to disable this function.                                                                   |
| `--default-log-file=FILE`  | Since ver. 9.25, Sets default log file for existing and future loggers. You may want to consider defining `_ELPP_NO_DEFAULT_LOG_FILE` to prevent creation of default empty log file during pre-processing. See macros section to disable this function.                                                                           |

 [![top] Goto Top](#table-of-contents)

### Configuration Macros
Some of logging options can be set by macros, this is a thoughtful decision, for example if we have `_ELPP_THREAD_SAFE` defined, all the thread-safe functionalities are enabled otherwise disabled (making sure over-head of thread-safety goes with it). To make it easy to remember and prevent possible conflicts, all the macros start with _ELPP_

|   Macro Name                             |                 Description                                                                                                                        |
|------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| `_ELPP_STOP_ON_FIRST_ASSERTION`          | Aborts application on first assertion failure. This assertion is due to invalid input e.g, invalid configuration file etc.                         |
| `_ELPP_THREAD_SAFE`                      | Enables thread-safety - make sure -lpthread linking for linux.                                                                                     |
| `_ELPP_STACKTRACE_ON_CRASH`              | Applicable to GCC only. Enables stacktrace on application crash                                                                                    |
| `_ELPP_DISABLE_DEFAULT_CRASH_HANDLING`   | Disables default crash handling. You can use el::Helpers::setCrashHandler to use your own handler.                                                 |
| `_ELPP_DISABLE_LOGS`                     | Disables all logs - (preprocessing)                                                                                                                |
| `_ELPP_DISABLE_DEBUG_LOGS`               | Disables debug logs - (preprocessing)                                                                                                              |
| `_ELPP_DISABLE_INFO_LOGS`                | Disables info logs - (preprocessing)                                                                                                               |
| `_ELPP_DISABLE_WARNING_LOGS`             | Disables warning logs - (preprocessing)                                                                                                            |
| `_ELPP_DISABLE_ERROR_LOGS`               | Disables error logs - (preprocessing)                                                                                                              |
| `_ELPP_DISABLE_FATAL_LOGS`               | Disables fatal logs - (preprocessing)                                                                                                              |
| `_ELPP_DISABLE_VERBOSE_LOGS`             | Disables verbose logs - (preprocessing)                                                                                                            |
| `_ELPP_DISABLE_TRACE_LOGS`               | Disables trace logs - (preprocessing)                                                                                                              |
| `_ELPP_DISABLE_VMODULES_EXTENSION`       | Disables vmodules extension. This means if you have a vmodule -vmodule=main*=4 it will cover everything starting with main, where as if you do not have this defined you will be covered for any file starting with main and ending with one of the following extensions; .h .c .cpp .cc .cxx .-inl-.h .hxx .hpp. Please note following vmodule is not correct -vmodule=main.*=4 with this macro not defined because this will check for main..c, notice double dots. If you want this to be valid, have a look at logging flag above: AllowVerboseIfModuleNotSpecified '?' and '*' wildcards are supported                                                                                                                                                                                       |
| `_ELPP_DISABLE_PERFORMANCE_TRACKING`     | Disables performance tracking - regardless of what logger is used - (preprocessing)                                                                |
| `_ELPP_FORCE_ENV_VAR_FROM_BASH`          | If environment variable could not be found, force using alternative bash command to find value, e.g, `whoami` for username. (DO NOT USE THIS MACRO WITH `LD_PRELOAD` FOR LIBRARIES THAT ARE ALREADY USING Easylogging++ OR YOU WILL END UP IN STACK OVERFLOW FOR PROCESSES (`popen`) (see [issue #87](https://github.com/easylogging/easyloggingpp/issues/87) for details))                                                                                                                                                                                       |
| `_ELPP_DEFAULT_LOG_FILE`                 | Full filename where you want initial files to be created. You need to embed value of this macro with quotes, e.g, `-D_ELPP_DEFAULT_LOG_FILE='"logs/el.gtest.log"'` Note the double quotes inside single quotes, double quotes are the values for `const char*` and single quotes specifies value of macro                                                                                 |
| `_ELPP_NO_DEFAULT_LOG_FILE`              | (since ver. 9.13) If you dont want to initialize library with default log file, define this macro. But be sure to configure your logger with propery log filename or you will end up getting heaps of errors when trying to log to file (and `TO_FILE` is configured to `true`)                                                                                                              |
| `_ELPP_ENABLE_ERRORS`                    | If you wish to find out internal errors raised by Easylogging++ that can be because of configuration or something else, you can enable them by defining this macro. You will get your errors on standard output i.e, terminal or command prompt.                                                                                                                                             |
| `_ELPP_DISABLE_CUSTOM_FORMAT_SPECIFIERS` | Forcefully disables custom format specifiers                                                                                                       |
| `_ELPP_DISABLE_LOGGING_FLAGS_FROM_ARG`   | Forcefully disables ability to set logging flags using command-line arguments                                                                      |
| `_ELPP_DISABLE_LOG_FILE_FROM_ARG`        | Forcefully disables ability to set default log file from command-line arguments                                                                    |

 [![top] Goto Top](#table-of-contents)
 
### Reading Configurations
If you wish to read configurations of certain logger, you can do so by using `typedConfigurations()` function in Logger class.
```c++
el::Logger* l = el::Loggers::getLogger("default");
bool enabled = l->typedConfigurations()->enabled(el::Level::Info);
// Or to read log format/pattern
std::string format = 
        l->typedConfigurations()->logFormat(el::Level::Info).format();
```

 [![top] Goto Top](#table-of-contents)
 
# Logging
Logging in easylogging++ is done using collection of macros. This is to make it easier for user and to prevent them knowing about unnecessary greater details of how things are done. If you further wish to know how things are done, refer to section "Design" below.

### Basic
You are provided with two basic macros that you can use in order to write logs:
* `LOG(LEVEL)`
* `CLOG(LEVEL, logger ID)`

`LOG` uses 'default' logger while in CLOG (Custom LOG) you specify the logger ID. For LEVELs please refer to Configurations - Levels section above. Different loggers might have different configurations depending on your need, you may as well write custom macro to access custom logger. You also have different macros for verbose logging that is explained in section below.
Here is very simple example of using these macros after you have initialized easylogging++.
```c++
LOG(INFO) << "This is info log";
CLOG(ERROR, "performance") << "This is info log using performance logger";
```

 [![top] Goto Top](#table-of-contents)
 
### Conditional Logging
Easylogging++ provides certain aspects of logging, one these aspects is conditional logging, i.e, log will be written only if certain condition fulfils. This comes very handy in some situations. 
Helper macros end with _IF;
* `LOG_IF(condition, LEVEL)`
* `CLOG_IF(condition, LEVEL, logger ID)`


#### Some examples:
```c++
LOG_IF(condition, INFO) << "Logged if condition is true";

LOG_IF(false, WARNING) << "Never logged";
CLOG_IF(true, INFO, "performance") << "Always logged (performance logger)"
```

Same macros are available for verbose logging with V in the beginning, i.e, `VLOG_IF` and `CVLOG_IF`. see verbose logging section below for further information. You may have as complicated conditions as you want depending on your need.

 [![top] Goto Top](#table-of-contents)
 
### Occasional Logging
Occasional logging is another useful aspect of logging with Easylogging++. This means a log will be written if it's hit certain times or part of certain times, e.g, every 10th hit or 100th hit or 2nd hit.
Helper macros end with `_EVERY_N`;
* `LOG_EVERY_N(n, LEVEL)`
* `CLOG_EVERY_N(n, LEVEL, logger ID)`

#### Some examples:
```c++
for (int i = 1; i <= 10; ++i) {
   LOG_EVERY_N(2, INFO) << "Logged every second iter";
}

// 5 logs written; 2, 4, 6, 7, 10
```

> Since ver. 9.18, same versions of macros are available for DEBUG only mode, these macros start with `D` (for debug) followed by the same name. e.g, `DLOG` to log only in debug mode (i.e, when `_DEBUG` is defined or `NDEBUG` is undefined)

 [![top] Goto Top](#table-of-contents)
 
### Verbose Logging
#### Basic
Verbose logging is useful in every software to record more information than usual. Very useful for troubleshooting. Following are verbose logging specific macros;
* `VLOG(verbose-level)`
* `CVLOG(verbose-level, logger ID)`

 [![top] Goto Top](#table-of-contents)
 
#### Conditional and Occasional Logging
Verbose logging also has conditional and occasional logging aspects i.e,
* `VLOG_IF(condition, verbose-level)`
* `CVLOG_IF(condition, verbose-level, loggerID)`
* `VLOG_EVERY_N(n, verbose-level)`
* `CVLOG_EVERY_N(n, verbose-level, loggerID)`

 [![top] Goto Top](#table-of-contents)

 
#### Verbose-Level
Verbose level is level of verbosity that can have range of 1-9. Verbose level will not be active unless you either set application arguments for it. Please read through [Application Arguments](#application-arguments) section to understand more about verbose logging.

 [![top] Goto Top](#table-of-contents)
 
#### Check If Verbose Logging Is On
You can use a macro VLOG_IS_ON(verbose-level) to check to see if certain logging is on for source file for specified verbose level. This returns boolean that you can embed into if condition.
```c++
if (VLOG_IS_ON(2)) {
   // Verbosity level 2 is on for this file
}
```

 [![top] Goto Top](#table-of-contents)
 
#### VModule
VModule is functionality for verbose logging (as mentioned in above table) where you can specify verbosity by modules/source file. Following are some examples with explanation; Any of vmodule below starts with -vmodule= and _ELPP_DISABLE_VMODULES_EXTENSION not defined

Example with `AllowVerboseIfModuleNotSpecified` flag;

`main=3,parser*=4`:
 * A bad example but good enough for explanation;
 * Verbosity for any following file will be allowed;
    `main{.h, .c, .cpp, .cc, .cxx, -inl.h, .hxx, .hpp}`
    `parser{.h, .c, .cpp, .cc, .cxx, -inl.h, .hxx, .hpp}`
 * No other file will be logged for verbose level

Example with no `AllowVerboseIfModuleNotSpecified` flag;

`main=3,parser*=4`:
 Same explanation but any other file that does not fall under specified modules will have verbose logging enabled.

 [![top] Goto Top](#table-of-contents)
 
### STL Logging
As mentioned earlier, with easylogging++, you can log your STL templates including most containers. In order to do so you will need to define `_ELPP_STL_LOGGING` macro. This enables including all the necessary headers and defines all necessary functions.
For performance, containers are limited to log maximum of 100 entries. This behaviour can be changed by changed header file (base::consts::kMaxLogPerContainer) but not recommended as in order to log, writer has to go through each entry causing potential delays. But if you are not really concerned with performance, you may change this value.

 [![top] Goto Top](#table-of-contents)
 
#### Supported Templates
Following templates are supported as part of STL Logging; note: basic and primitive types e.g, std::string or long are not listed as they is supported anyway, following list only contains non-basic types e.g, containers or bitset etc.

|     *       |          *              |       *          |       *          |
|-------------|-------------------------|------------------|------------------|
| std::vector |  std::list              |  std::deque      |    std::queue    |
| std::stack  |  std::priority_queue    |  std::set        |    std::multiset |
| std::pair   |  std::bitset            |  std::map        |    std::multimap |

Some C++11 specific templates are supported by further explicit macro definitions; note these also need `_ELPP_STL_LOGGING`

|   Template              |     Macro Needed            |
|-------------------------|-----------------------------|
| std::array              | `_ELPP_LOG_STD_ARRAY`       |
| std::unordered_map      | `_ELPP_LOG_UNORDERED_MAP`   |
| std::unordered_multimap | `_ELPP_LOG_UNORDERED_MAP`   |
| std::unordered_set      | `_ELPP_LOG_UNORDERED_SET`   |
| std::unordered_multiset | `_ELPP_LOG_UNORDERED_SET`   |

Standard manipulators are also supported, in addition std::stringstream is also supported.

 [![top] Goto Top](#table-of-contents)
 
### Registering New Loggers
Loggers are unique in logger repository by ID. You can register new logger the same way as you would get logger. Using `getLogger(.., ..)` from `el::Loggers` helper class. This function takes two params, first being ID and second being boolean (optional) to whether or not to register new logger if does not already exist and returns pointer to existing (or newly created) el::Logger class. This second param is optional and defaults to true. If you set it to false and logger does not exist already, it will return nullptr.

By default, Easylogging++ registers three loggers (+ an internal logger);
* Default logger (ID: `default`)
* Performance logger (ID: `performance`)
* Syslog logger (if `_ELPP_SYSLOG` macro is defined) (ID: `syslog`)

If you wish to register a new logger, say e.g, with ID `business`
```c++
el::Logger* businessLogger = el::Loggers::getLogger("business");
```	

This will register a new logger if it does not already exist otherwise it will get an existing one. But if you have passed in `false` to the second param and logger does not already exist, `businessLogger` will be nullptr.

When you register a new logger, default configurations are used (see Default Configurations section above). Also worth noticing, logger IDs are case sensitive.

 [![top] Goto Top](#table-of-contents)
 
### Populating Existing Logger IDs
Although this is a rare situation but if you wish to get list of all the logger IDs currently in repository, you may use `el::Loggers::populateAllLoggerIds(std::vector<std::string>&)` function to do that. The list passed in is cleared and filled up with all existing logger IDs.

 [![top] Goto Top](#table-of-contents)
 
# Extra Features
Easylogging++ is feature-rich logging library. Apart from features already mentioned above, here are some extra features. If code snippets don't make sense and further sample is needed, there are many samples available at github repository (samples). Feel free to browse around.

### Performance Tracking
One of the most notable features of Easylogging++ is its ability to track performance of your function or block of function. 
Please note, this is not backward compatible as previously we had bad macros that user must had defined in order to track performance and I am sure many users had avoided in doing so. (Read v8.91 ReadMe for older way of doing it)
The new way of tracking performance is much easier and reliable. All you need to do is use one of two macros from where you want to start tracking.
* `TIMED_FUNC(obj-name)`
* `TIMED_SCOPE(obj-name, block-name)`
* `TIMED_BLOCK(obj-name, block-name)`

An example that just uses usleep 
```c++
void performHeavyTask(int iter) {
   TIMED_FUNC(timerObj);
   // Some initializations
   // Some more heavy tasks
   usleep(5000);
   while (iter-- > 0) {
       TIMED_SCOPE(timerBlkObj, "heavy-iter");
       // Perform some heavy task in each iter
       usleep(10000);
   }
}
```
	 
The result of above execution for iter = 10, is as following
```
06:22:31,368 INFO Executed [heavy-iter] in [10 ms]
06:22:31,379 INFO Executed [heavy-iter] in [10 ms]
06:22:31,389 INFO Executed [heavy-iter] in [10 ms]
06:22:31,399 INFO Executed [heavy-iter] in [10 ms]
06:22:31,409 INFO Executed [heavy-iter] in [10 ms]
06:22:31,419 INFO Executed [heavy-iter] in [10 ms]
06:22:31,429 INFO Executed [heavy-iter] in [10 ms]
06:22:31,440 INFO Executed [heavy-iter] in [10 ms]
06:22:31,450 INFO Executed [heavy-iter] in [10 ms]
06:22:31,460 INFO Executed [heavy-iter] in [10 ms]
06:22:31,460 INFO Executed [void performHeavyTask(int)] in [106 ms]
```

In the above example, we have used both the macros. In line-2 we have `TIMED_FUNC` with object name timerObj and line-7 we have TIMED_SCOPE with object name `timerBlkObj` and block name `heavy-iter`. Notice how block name is thrown out to the logs with every hit.  (Note: `TIMED_FUNC` is `TIMED_BLOC` with block name = function name)

You might wonder why do we need object name. Well easylogging++ performance tracking feature takes it further and provides ability to add, what's called checkpoints. 
Checkpoints have two macros:
* `PERFORMANCE_CHECKPOINT(timed-block-obj-name)`
* `PERFORMANCE_CHECKPOINT_WITH_ID(timed-block-obj-name, id)`

Take a look at following example
```c++
void performHeavyTask(int iter) {
   TIMED_FUNC(timerObj);
   // Some initializations
   // Some more heavy tasks
   usleep(5000);
   while (iter-- > 0) {
       TIMED_SCOPE(timerBlkObj, "heavy-iter");
       // Perform some heavy task in each iter
       // Notice following sleep varies with each iter
       usleep(iter * 1000);
       if (iter % 3) {
           PERFORMANCE_CHECKPOINT(timerBlkObj);
       }
   }
}
```

Notice macro on line-11 (also note comment on line-8. It's checkpoint for heavy-iter block. Now notice following output
```
06:33:07,558 INFO Executed [heavy-iter] in [9 ms]
06:33:07,566 INFO Performance checkpoint for block [heavy-iter] : [8 ms]
06:33:07,566 INFO Executed [heavy-iter] in [8 ms]
06:33:07,573 INFO Performance checkpoint for block [heavy-iter] : [7 ms]
06:33:07,573 INFO Executed [heavy-iter] in [7 ms]
06:33:07,579 INFO Executed [heavy-iter] in [6 ms]
06:33:07,584 INFO Performance checkpoint for block [heavy-iter] : [5 ms]
06:33:07,584 INFO Executed [heavy-iter] in [5 ms]
06:33:07,589 INFO Performance checkpoint for block [heavy-iter] : [4 ms]
06:33:07,589 INFO Executed [heavy-iter] in [4 ms]
06:33:07,592 INFO Executed [heavy-iter] in [3 ms]
06:33:07,594 INFO Performance checkpoint for block [heavy-iter] : [2 ms]
06:33:07,594 INFO Executed [heavy-iter] in [2 ms]
06:33:07,595 INFO Performance checkpoint for block [heavy-iter] : [1 ms]
06:33:07,595 INFO Executed [heavy-iter] in [1 ms]
06:33:07,595 INFO Executed [heavy-iter] in [0 ms]
06:33:07,595 INFO Executed [void performHeavyTask(int)] in [51 ms]
```

You can also compare two checkpoints if they are in sub-blocks e.g, changing from `PERFORMANCE_CHECKPOINT(timerBlkObj)` to `PERFORMANCE_CHECKPOINT(timerObj)` will result in following output
```
06:40:35,522 INFO Performance checkpoint for block [void performHeavyTask(int)] : [51 ms ([1 ms] from last checkpoint)]
```

If you had used `PERFORMANCE_CHECKPOINT_WITH_ID(timerObj, "mychkpnt");` instead, you will get
```
06:44:37,979 INFO Performance checkpoint [mychkpnt] for block [void performHeavyTask(int)] : [51 ms ([1 ms] from checkpoint 'mychkpnt')]
```

Following are some useful macros that you can define to change the behaviour

|   Macro Name                                        |                 Description                                                                                                    |
|-----------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| `_ELPP_PERFORMANCE_DISABLE_COMPARE_CHECKPOINTS`     | Disables checkpoint comparison                                                                                                 |
| `_ELPP_DISABLE_PERFORMANCE_TRACKING`                | Disables performance tracking                                                                                                  |
| `_ELPP_PERFORMANCE_MICROSECONDS`                    | Track up-to microseconds (this includes initializing of el::base::Trackable as well so might time not be 100% accurate)        |

Notes:

1. Performance tracking uses `performance` logger (INFO level) by default unless `el::base::Trackable` is constructed manually (not using macro - not recommended). When configuring other loggers, make sure you configure this one as well.

2. In above examples, `timerObj` and `timerBlkObj` is of type `el::base::Trackable` and `checkpoint()` can be accessed by `timerObj.checkpoint()` but not recommended as this will override behaviour of using macros, behaviour like location of checkpoint.

3. `TIMED_BLOCK` in older version (before ver 9.25) has been renamed to `TIMED_SCOPE` and functionality of `TIMED_BLOCK` is new

4. In order to access `el::base::Trackable` while in `TIMED_BLOCK`, you can use `timerObj.timer`

5. `TIMED_BLOCK` macro resolves to a single-looped for-loop, so be careful where you define `TIMED_BLOCK`, if for-loop is allowed in the line where you use it, you should have no errors.

 [![top] Goto Top](#table-of-contents)
 
### Log File Rolling
Easylogging++ has ability to roll out (or throw away) log files if they reach certain limit. You can configure this by setting `Max_Log_File_Size`. See Configuration section above.

This feature has it's own section in this reference manual because you can do stuffs with the file being thrown away. This is useful, for example if you wish to back this file up etc.
This can be done by using `el::Helpers::installPreRollOutHandler(const base::PreRollOutHandler& handler)` where `PreRollOutHandler` is typedef of type `std::function<void(const char*, std::size_t)>`. Please note following if you are using this feature

> You should not log anything in this function. This is because logger would already be locked in multi-threaded application and you can run into dead lock conditions. If you are sure that you are not going to log to same file and not using same logger, feel free to give it a try.

 [![top] Goto Top](#table-of-contents)

### Crash Handling
Easylogging++ provides ability to handle unexpected crashes for GCC compilers. This is active by default and can be disabled by defining macro `_ELPP_DISABLE_DEFAULT_CRASH_HANDLING`. By doing so you are telling library not to handle any crashes. Later on if you wish to handle crash yourself, you can assign crash handler of type void func(int) where int is signal caught. 

Following signals are handled;
* SIGABRT (If `_ELPP_HANDLE_SIGABRT` macro is defined)
* SIGFPE
* SIGILL
* SIGSEGV
* SIGINT

Stacktraces are not printed by default, in order to do so define macro `_ELPP_STACKTRACE_ON_CRASH`. Remember, stack trace is only available for GCC compiler.

> Default handler and stack trace uses `default` logger.

Following are some useful macros that you can define to change the behaviour

|   Macro Name                                        |                 Description                                                                                                    |
|-----------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| `_ELPP_DISABLE_DEFAULT_CRASH_HANDLING`              | Disables default crash handling.                                                                                               |
| `_ELPP_HANDLE_SIGABRT`                              | Enables handling `SIGABRT`. This is disabled by default to prevent annoying `CTRL + C` behaviour when you wish to abort.       |

 [![top] Goto Top](#table-of-contents)

#### Installing Custom Crash Handlers
You can use your own crash handler by using `el::Helpers::setCrashHandler(const el::base::debug::CrashHandler::Handler&);`. 

> Make sure to abort application at the end of your crash handler using `el::Helpers::crashAbort(int)`. If you fail to do so, you will get into endless loop of crashes.

Here is a good example of your own handler
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

void myCrashHandler(int sig) {
    LOG(ERROR) << "Woops! Crashed!";     
    // FOLLOWING LINE IS ABSOLUTELY NEEDED AT THE END IN ORDER TO ABORT APPLICATION
    el::Helpers::crashAbort(sig);
}
int main(void) {
    el::Helpers::setCrashHandler(myCrashHandler);

    LOG(INFO) << "My crash handler!";

    int* i;
    *i = 0; // Crash!

    return 0;
}
```

> If you wish to log reason for crash you can do so by using `el::Helpers::logCrashReason(int, bool, const el::Level&, const char*)`. Following are default parameters for this function:
```c++
>  bool stackTraceIfAvailable = false
>  const el::Level& level = el::Level::Fatal
>  const char* logger = "default"
```

 [![top] Goto Top](#table-of-contents)

### Stacktrace
Easylogging++ 9.0+ supports stack trace printing for GCC compilers. You can print stack trace at anytime by calling `el::base::debug::StackTrace()`, formatting will be done automatically. Note, if you are using non-GCC compiler, you will end-up getting empty output.

 [![top] Goto Top](#table-of-contents)
 
### Multi-threading
Easylogging++ is thread-safe. By default thread-safety is disabled. You can enable it by defining `_ELPP_THREAD_SAFE` otherwise you will see unexpected results. This is intentional to make library efficient for single threaded application.

 [![top] Goto Top](#table-of-contents)
 
### CHECK Macros
Easylogging++ supports CHECK macros, with these macros you can quickly check whether certain condition fulfills or not. If not Easylogging++ writes FATAL log, causing application to stop (unless defined macro to prevent stopping application on fatal).

|                     CHECK Name              |                 Notes + Example                                                                                                 |
|---------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------|
| `CHECK(condition)`                          | Checks for condition e.g, `CHECK(isLoggedIn()) << "Not logged in";`                                                             |
| `CHECK_EQ(a, b)`                            | Equality check e.g, `CHECK_EQ(getId(), getLoggedOnId()) << "Invalid user logged in";`                                           |
| `CHECK_NE(a, b)`                            | Inequality check e.g, `CHECK_NE(isUserBlocked(userId), false) << "User is blocked";`                                            |
| `CHECK_LT(a, b)`                            | Less than e.g, `CHECK_LT(1, 2) << "How 1 is not less than 2";`                                                                  |
| `CHECK_GT(a, b)`                            | Greater than e.g, `CHECK_GT(2, 1) << "How 2 is not greater than 1?";`                                                           |
| `CHECK_LE(a, b)`                            | Less than or equal e.g, `CHECK_LE(1, 1) << "1 is not equal or less than 1";`                                                    |
| `CHECK_GE(a, b)`                            | Greater than or equal e.g, `CHECK_GE(1, 1) << "1 is not equal or greater than 1";`                                              |
| `CHECK_NOTNULL(pointer)`                    | Ensures pointer is not null - if OK returns pointer e.g, `explicit MyClass(Obj* obj) : m_obj(CHECK_NOT_NULL(obj)) {}`           |
| `CHECK_STREQ(str1, str2)`                   | C-string equality (case-sensitive) e.g, `CHECK_STREQ(argv[1], "0") << "First arg cannot be 0";`                                 |
| `CHECK_STRNE(str1, str2)`                   | C-string inequality (case-sensitive) e.g, `CHECK_STRNE(username1, username2) << "Usernames cannot be same";`                    |
| `CHECK_STRCASEEQ(str1, str2)`               | C-string inequality (*case-insensitive*) e.g, `CHECK_CASESTREQ(argv[1], "Z") << "First arg cannot be 'z' or 'Z'";`              |
| `CHECK_STRCASENE(str1, str2)`               | C-string inequality (*case-insensitive*) e.g, `CHECK_STRCASENE(username1, username2) << "Same username not allowed";`           |

> Since ver. 9.18, same versions of macros are available for DEBUG only mode, these macros start with `D` (for debug) followed by the same name. e.g, `DCHECK` to check only in debug mode (i.e, when `_DEBUG` is defined or `NDEBUG` is undefined)

 [![top] Goto Top](#table-of-contents)
 
### Logging perror()
Easylogging++ supports `perror()` styled logging using `PLOG(LEVEL)`, `PLOG_IF(Condition, LEVEL)`, and `PCHECK()` using `default` logger; and for custom logger use `CPLOG(LEVEL, LoggerId)`, `CPLOG_IF(Condition, LEVEL, LoggerId)`. This will append `: log-error [errno]` in the end of log line.

> Since version 9.23

 [![top] Goto Top](#table-of-contents)

### Syslog
Easylogging++ supports syslog for platforms that have `syslog.h` header. In order to enable it, you need to define `_ELPP_SYSLOG`. If your platform does not have `syslog.h`, make sure you do not define this macro or you will end up in errors. Once you are ready to use syslog, you can do so by using one of `SYSLOG(LEVEL)`, `SYSLOG_IF(Condition, LEVEL)`, `SYSLOG_EVERY_N(n, LEVEL)` and uses logger ID: `syslog`. If you want to use custom logger you can do so by using `CSYSLOG(LEVEL, loggerId)` or `CSYSLOG_IF(Condition, LEVEL, loggerId)` or `CSYSLOG_EVERY_N(n, LEVEL, loggerId)`

Syslog in Easylogging++ supports C++ styled streams logging, following example;
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP
int main(void) {
    _INIT_SYSLOG("my_proc", LOG_PID | LOG_CONS | LOG_PERROR, LOG_USER) // This is optional, you may not add it if you dont want to specify options
    // Alternatively you may do
    // el::SysLogInitializer elSyslogInit("my_proc", LOG_PID | LOG_CONS | LOG_PERROR, LOG_USER);
    SYSLOG(INFO) << "This is syslog - read it from /var/log/syslog"
    return 0;
}
```

Syslog support for Easylogging++ only supports following levels; each level is corresponded with syslog priority as following

 * INFO (LOG_INFO)
 * DEBUG (LOG_DEBUG)
 * WARNING (LOG_WARNING)
 * ERROR (LOG_ERR)
 * FATAL (LOG_EMERG)

Following levels are not supported and correspond to `LOG_NOTICE`: TRACE, whereas VERBOSE level is completely not supported

> Since version 9.24

 [![top] Goto Top](#table-of-contents)
 
### Qt Logging
Easylogging++ has complete logging support for Qt core library. define `_ELPP_QT_LOGGING` macro. This will include all the headers supported Qt logging. Once you did that, you should be good to go.

Following Qt classes and containers are supported by Easylogging++ v9.0+

|     *         |          *                |       *            |         *          |         *          |         *          |
|---------------|---------------------------|--------------------|--------------------|--------------------|--------------------|
| `QString`     |  `QByteArray`             |  `QLatin`          |    `QList`         |    `QVector`       |    `QQueue`        |
| `QSet`        |  `QPair`                  |  `QMap`            |    `QMultiMap`     |    `QHash`         |    `QMultiHash`    |
| `QLinkedList` |  `QStack`                 |  `QChar`           |    `q[u]int[64]`   |                    |                    |

`QBool` is not supported since it's been dropped from Qt 5+

Similar to STL logging, Qt containers are also limit to log 100 entries per log, you can change this behaviour by changing base::consts::kMaxLogPerContainer from header but this is not recommended as this was done for performance purposes.

Also note, if you are logging a container that contains custom class, make sure you have read Extending Library section below.

 [![top] Goto Top](#table-of-contents)

### Boost Logging
Easylogging++ supports some of boost templates. In order to enable boost logging, define macro `_ELPP_BOOST_LOGGING`

Following table shows the templates supported.

|     *                               |          *                               |
|-------------------------------------|------------------------------------------|
| `boost::container::vector`          |  `boost::container::stable_vector`       |
| `boost::container::map`             |  `boost::container::flat_map`            |
| `boost::container::set`             |  `boost::container::flat_set`            |
| `boost::container::deque`           |  `boost::container::list`                |
| `boost::container::string`          |                                          |

> Since version 9.06

 [![top] Goto Top](#table-of-contents)

### wxWidgets Logging
Easylogging++ supports some of wxWidgets templates. In order to enable wxWidgets logging, define macro `_ELPP_WXWIDGETS_LOGGING`

Following table shows the templates supported.

|     *               |          *        |      *                    |      *                    |      *              |      *               |
|---------------------|-------------------|---------------------------|---------------------------|---------------------|----------------------|
| `wxString`          |  `wxVector`       |  `wxList`                 |  `wxString`               | `wxHashSet`         |  `wxHashMap`         |

wxWidgets has its own way of declaring and defining some templates e.g, `wxList` where  you use `WX_DECLARE_LIST` macro to declare a list.

In order to setup a container for logging that holds pointers to object, use `ELPP_WX_PTR_ENABLED`, otherwise if container holds actual object e.g, wxHashSet use `ELPP_WX_ENABLED`. For containers like `wxHashMap` because it contains value and pair, use `ELPP_WX_HASH_MAP_ENABLED` macro.

```c++
// wxList example
WX_DECLARE_LIST(int, MyList);
WX_DEFINE_LIST(MyList);
// Following line does the trick
ELPP_WX_PTR_ENABLED(MyList);

// wxHashSet example
WX_DECLARE_HASH_SET(int, wxIntegerHash, wxIntegerEqual, IntHashSet);
// Following line does the trick!
ELPP_WX_ENABLED(IntHashSet)

// wxHashMap example
WX_DECLARE_STRING_HASH_MAP(wxString, MyHashMap);
// Following line does the trick
ELPP_WX_HASH_MAP_ENABLED(MyHashMap)
```
You may also have a look at wxWidgets sample

> Since version 9.09

 [![top] Goto Top](#table-of-contents)

### Extending Library

> This functionality has been improved since version 9.12. For older versions, please refer to [older manual](https://github.com/easylogging/easyloggingpp/blob/v9.24/README.md)

#### Logging Your Own Class

You can log your own classes by extending `el::Loggable` class and implementing pure-virtual function `void log(std::ostream& os) const`. Following example shows a good way to extend a class.
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP
class Integer : public el::Loggable {
public:
    Integer(int i) : m_underlyingInt(i) {
    }
    Integer& operator=(const Integer& integer) {
        m_underlyingInt = integer.m_underlyingInt;
        return *this;
    }
    // Following line does the trick!
    virtual void log(std::ostream& os) const {
        os << m_underlyingInt;
    }
private:
    int m_underlyingInt;
};

int main(void) {
    Integer count = 5;
    LOG(INFO) << count;
    return 0;
}
```

 [![top] Goto Top](#table-of-contents)

#### Logging Third-party Class
Let's say you have third-party class that you don't have access to make changes to, and it's not yet loggable. In order to make it loggable, you can use `MAKE_LOGGABLE(ClassType, ClassInstance, OutputStreamInstance)` to make it Easylogging++ friendly.

Following sample shows a good usage:
```c++
#include "easylogging++.h"

_INITIALIZE_EASYLOGGINGPP

class Integer {
public:
    Integer(int i) : m_underlyingInt(i) {
    }
    Integer& operator=(const Integer& integer) {
        m_underlyingInt = integer.m_underlyingInt;
        return *this;
    }
    int getInt(void) const { return m_underlyingInt; }
private:
    int m_underlyingInt;
};

// Following line does the trick!
inline MAKE_LOGGABLE(Integer, integer, os) {
    os << integer.getInt();
    return os;
}
int main(void) {
    Integer count = 5;
    LOG(INFO) << count;
    return 0;
}
```

Just be careful with this as having a time-consuming overloading of `log(std::ostream& os)` and `MAKE_LOGGABLE`, they get called everytime class is being logged.

 [![top] Goto Top](#table-of-contents)

### Manually Flushing and Rolling Log Files
You can manually flush log files using `el::Logger::flush()` (to flush single logger with all referencing log files) or `el::Loggers::flushAll()` (to flush all log files for all levels).

If you have not set flag `LoggingFlag::StrictLogFileSizeCheck` for some reason, you can manually check for log files that need rolling; by using `el::Helpers::validateFileRolling(el::Logger*, const el::Level&)`. 

 > Since ver. 9.25

 [![top] Goto Top](#table-of-contents)

# Contribution
### Submitting Patches
Since ver. 9.25, we do not accept any patches. Contribution can only be done by report bugs. This is because Easylogging++ is based on single header file hence we run into conflicts a lot of times, which no developer likes.

 [![top] Goto Top](#table-of-contents)
 
### Reporting a Bug
If you have found a bug and wish to report it, feel free to do so at [github issue tracker](https://github.com/easylogging/easyloggingpp/issues?state=open). I will try to look at it as soon as possible. Some information should be provided to make it easy to reproduce;
* Platform (OS, Compiler)
* Log file location
* Macros defined (on compilation) OR simple compilation 
* Please assign issue label.

Try to provide as much information as possible. Any bug with no clear information will be ignored and closed.

 [![top] Goto Top](#table-of-contents)

### Donation

Easylogging++ is free to use for any type of software but it costs money to maintain the project and to run website (easylogging.org), so donations are very well accepted on your will. You can donate via paypal or by using credit card by going to http://easylogging.org and clicking 'Donate' on the bottom. 

But please be sure the donation money is halaal in islam in every aspect, meaning it's not money from interest paid by bank or stolen etc. Have a look at [this document](http://www.auscif.com/wp-content/uploads/2012/09/Halal-Money-Guide-2012.pdf) for further details on what's halaal and what's not (haraam)

[![pledgie]](http://www.pledgie.com/campaigns/22070)

 [![top] Goto Top](#table-of-contents)

# Compatibility

Easylogging++ requires a decent C++0x complient compiler. Some compilers known to work with v9.0+ are shown in table below, for older versions please refer to readme on corresponding release at github

| *****   |     Compiler/Platform     |      Notes                                                                                                                                               |
|---------|---------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
|![gcc]   | GCC 4.7+                  | Stack trace logging. Very close to support GCC 4.6 if it had supported strong enum types casting to underlying type. It causes internal compiler error.  |
|![llvm]  | Clang++ 3.1+              | Stack trace logging only with gcc compliant.                                                                                                             |
|![intel] | Intel C++ 13.0+           | Workarounds to support: Use if instead of switch on strong enum type. No `final` keyword etc. Stack trace logging only with gcc compliant                |
|![vcpp]  | Visual C++ 11.0+          | Tested with VS2012, VS2013-Preview; Use of argument templates instead of variadic templates. CRT warnings control. No stack trace logging.               |
|![mingw] | MinGW                     | (gcc version 4.7+) Workarounds to support: Mutex wrapper, no stack trace logging. No thread ID on windows                                                |
|![tdm]   | TDM-GCC 4.7.1             | Tested with TDM-GCC 4.7.1 32 and 64 bit compilers                                                                                                        |
|![cygwin]| Cygwin                    | Tested with gcc version 4.8+                                                                                                                             |
|![devcpp]| Dev C++ 5.4+              | Tested with Dev-C++ 5.4.2 using TDM-GCC 4.7.1 32 & 64-bit compilers                                                                                      |

Operating systems that have been tested are shown in table below. Easylogging++ should work on other major operating systems that are not in the list.

| *****     | Operating System       |   Notes                                                                             |
|-----------|------------------------|-------------------------------------------------------------------------------------|
|![win8]    | Windows 8              | Tested on 64-bit, should also work on 32-bit                                        |
|![win7]    | Windows 7              | Tested on 64-bit, should also work on 32-bit                                        |
|![winxp]   | Windows XP             | Tested on 32-bit, should also work on 64-bit                                        |
|![mac]     | Mac OSX                | Clang++ 3.1 (Tested by contributor)                                                 |
|![sl]      | Scientific Linux 6.2   | Tested using Intel C++ 13.1.3 (gcc version 4.4.6 compatibility)                     |
|![mint]    | Linux Mint 14          | 64-bit, mainly developed on this machine using all compatible linux compilers       |
|![fedora]  | Fedora 19              | 64-bit, using g++ 4.8.1                                                             |
|![ubuntu]  | Ubuntu 13.04           | 64-bit, using g++ 4.7.3 (libstdc++6-4.7-dev)                                        |
|![android] | Android                | Tested with C4droid (g++) on Galaxy Tab 2                                           |

Easylogging++ has also been tested with following C++ libraries;

| *****       | Library                |    Notes                                                                            |
|-------------|------------------------|-------------------------------------------------------------------------------------|
|![qt]        | Qt                     | Tested with Qt 4.6.2 and Qt 5 (with C++0x and C++11)                                |
|![boost]     | Boost                  | Tested with boost 1.51                                                              |
|![wxwidgets] | wxWidgets              | Tested with wxWidgets 2.9.4                                                         |
|![gtkmm]     | gtkmm                  | Tested with gtkmm 2.4                                                               |

 [![top] Goto Top](#table-of-contents)
 
# Licence
```
The MIT License (MIT)

(c) Copyright 2013 Majid Khan
http://easylogging.org/

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
```

 [![top] Goto Top](#table-of-contents)
 
# Disclaimer
Icons used in this manual (in compatibility section) are solely for information readability purposes. I do not own these icons. If anyone has issues with usage of these icon, please feel free to contact me via company's email and I will look for an alternative. Company's email address is required so that I can verify the ownership, any other email address for this purpose will be ignored.

"Pencil +" icon is Easylogging++ logo and should only be used where giving credit to Easylogging++ library.


 [![top] Goto Top](#table-of-contents)
 
  [banner]: http://easylogging.org/images/banner.png?v=4
  [ubuntu]: http://www.easylogging.org/images/icons/ubuntu.png?v=2
  [mint]: http://www.easylogging.org/images/icons/linux-mint.png?v=2
  [sl]: http://www.easylogging.org/images/icons/scientific-linux.png?v=2
  [fedora]: http://www.easylogging.org/images/icons/fedora.png?v=3
  [mac]: http://www.easylogging.org/images/icons/mac-osx.png?v=2
  [winxp]: http://www.easylogging.org/images/icons/windowsxp.png?v=2
  [win7]: http://www.easylogging.org/images/icons/windows7.png?v=2
  [win8]: http://www.easylogging.org/images/icons/windows8.png?v=2
  [qt]: http://www.easylogging.org/images/icons/qt.png?v=3
  [boost]: http://www.easylogging.org/images/icons/boost.png?v=3
  [wxwidgets]: http://www.easylogging.org/images/icons/wxwidgets.png?v=3
  [devcpp]: http://www.easylogging.org/images/icons/devcpp.png?v=3
  [gtkmm]: http://www.easylogging.org/images/icons/gtkmm.png?v=3
  [tdm]: http://www.easylogging.org/images/icons/tdm.png?v=3

  [gcc]: http://www.easylogging.org/images/icons/gcc.png?v=4
  [mingw]: http://www.easylogging.org/images/icons/mingw.png?v=2
  [cygwin]: http://www.easylogging.org/images/icons/cygwin.png?v=2
  [vcpp]: http://www.easylogging.org/images/icons/vcpp.png?v=2
  [llvm]: http://www.easylogging.org/images/icons/llvm.png?v=2
  [intel]: http://www.easylogging.org/images/icons/intel.png?v=2
  [android]: http://www.easylogging.org/images/icons/android.png?v=2
  [manual]: http://easylogging.org/images/help.png?v=3
  [download]: http://easylogging.org/images/download.png?v=2
  [samples]: http://easylogging.org/images/sample.png?v=2
  [notes]: http://easylogging.org/images/notes.png?v=4
  [top]: http://easylogging.org/images/up.png?v=4
  [www]: http://easylogging.org/images/logo-www.png?v=6
  
  [pledgie]: http://www.pledgie.com/campaigns/22070.png?skin_name=chrome&v=2
