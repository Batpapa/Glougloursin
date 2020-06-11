#define MyAppName "GlougloursinCreator"
#define MyAppVersion "1.0"
#define MyAppPublisher "Mimi Company"
#define MyAppExeName "GlougloursinCreator.exe"

[Setup]
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=setup
OutputDir=deploy
SetupIconFile="..\Resources\icon.ico"
Compression=lzma2
SolidCompression=yes
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\..\build\release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs
Source: "..\Resources\icon.ico"; DestDir: "{app}"
Source: "..\Resources\iconFile.ico"; DestDir: "{app}"

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}";
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}";
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon;

[Registry]
Root: HKCR; Subkey: ".glouglou"; ValueType: string; ValueName: ""; ValueData: "GGFile"; Flags: uninsdeletevalue
Root: HKCR; Subkey: "GGFile"; ValueType: string; ValueName: ""; ValueData: "Glougloursin File"; Flags: uninsdeletekey
Root: HKCR; Subkey: "GGFile\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\iconFile.ico";
Root: HKCR; Subkey: "GGFile\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\{#MyAppExeName}"" ""%1"""

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent