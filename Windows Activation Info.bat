@echo off
chcp 65001 > nul

echo    Created by poJLikno
echo =========================

cscript //nologo slmgr.vbs /xpr & cscript //nologo slmgr.vbs /dli

pause