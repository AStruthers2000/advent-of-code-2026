# cpptools IntelliSense workers keep the module .ifc files open (no share-write/delete),
# which makes MSVC fail with C3474 on rebuild. The extension respawns workers on demand.
Get-Process -Name 'cpptools-srv', 'cpptools-srv2' -ErrorAction SilentlyContinue |
    ForEach-Object { Stop-Process -Id $_.Id -Force -ErrorAction SilentlyContinue }
exit 0
