chcp 65001 > nul
schtasks /create /xml "WinActor schedule.xml" /tn WinActor
pause
