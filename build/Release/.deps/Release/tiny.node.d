cmd_Release/tiny.node := ln -f "Release/obj.target/tiny.node" "Release/tiny.node" 2>/dev/null || (rm -rf "Release/tiny.node" && cp -af "Release/obj.target/tiny.node" "Release/tiny.node")
