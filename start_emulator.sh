#!/bin/bash
# Start local HTTP server for NES Emulator

cd "$(dirname "$0")" || exit

echo "🎮 Starting NES Emulator HTTP Server..."
echo "📂 Workspace: $(pwd)"
echo ""
echo "✅ Server will be accessible at: http://localhost:8000/emulator.html"
echo ""
echo "Press Ctrl+C to stop the server"
echo ""

python3 -m http.server 8000 --bind 127.0.0.1
