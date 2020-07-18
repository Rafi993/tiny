{
  "targets": [
    {
      "target_name": "addon",
      "cflags_cc": [
        "<!@(pkg-config gtk+-3.0 --cflags)",
        "<!@(pkg-config webkit2gtk-4.0 --cflags)"
      ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      "libraries": [
        '<!@(pkg-config gtk+-3.0 --libs)',
        '<!@(pkg-config webkit2gtk-4.0 --libs)'
      ],
      "sources": [ "./src/addon.cc", "./src/tiny.cc" ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}
