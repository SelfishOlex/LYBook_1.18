function LyProjectConfigurator()
{
    .\Bin64vc141\ProjectConfigurator.exe
}

function LyEditor()
{
    .\Bin64vc141\Editor.exe
}

function LyBuildAll()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile -p all
}

function LyBuildAllDedicated()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile_dedicated -p all
}

function LyBuild()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile -p game
}
function LyBuildDedicated()
{
    .\lmbr_waf.bat build_win_x64_vs2017_profile_dedicated -p game
}
function LyConfigure()
{
    .\lmbr_waf.bat configure -p game
}

function LyBuildTestAll() {
    .\lmbr_waf.bat build_win_x64_vs2017_profile_test -p all
}

function LyBuildTestDebugAll() {
    .\lmbr_waf.bat build_win_x64_vs2017_debug_test -p all
}
function Start-MyProject() {
    .\Bin64vc141.Dedicated\MyProjectLauncher_Server.exe +windowxy 5 5
    .\Bin64vc141\MyProjectLauncher.exe +windowxy 550 250 +mpjoin
}