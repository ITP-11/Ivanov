@echo off

Set "From=D:\edu\OS\Zadanie1"
Set "To=D:\edu\OS\test"

xcopy %From%\*.txt %To% /d /y /e
