# XXaml
XXaml is xaml for cross platforms. This is prototype now.

This library under Apache 2.0.

Remark: **This prototype has a lot of bugs.**


# The Goal of This Project

The goal is what supports a lot of platforms, Windows 8+, Windows 10 for all platforms, OS X/iOS, Gnome, KDE, Xfce, and Android. You can also use a lot of languages, .NET (C#, VB, F#, and more…), JVM (Java, Scala, and more…), native/LLVM (C++, Objective-C, Swift).

## Decision

- Support desktop environments: Windows, OS X/iOS, Gnome, Android
- Support languages: C++, Obj-C, .NET, JVM
- C++ - Java Binding: BridJ [https://code.google.com/p/bridj/]
- C++ header parsing and create binding source: clang/LLVM [http://llvm.org/]

## Plan

- Support desktop environments: KDE, Xfce
- Support languages: Swift
- C++ - C# Binding: CXXI (but have many problems) [https://github.com/mono/cxxi]
- cross xaml binary format: MsgPack (it is high performance) [http://msgpack.org/]