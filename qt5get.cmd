set QB=C:\Qt\5.15.6\msvc2019
set QDIR=%QB%\bin
set QDLL=.dll
set DST=.\RTE
mkdir %DST%
copy %QDIR%\Qt5Widgets%QDLL% %DST%
copy %QDIR%\Qt5Gui%QDLL% %DST%
copy %QDIR%\Qt5Core%QDLL% %DST%

mkdir %DST%\platforms
copy %QB%\plugins\platforms\qwindows%QDLL% %DST%\platforms\qwindows%QDLL%
copy ..\build-MCF8316Json2C-Desktop_Qt_5_15_6_MSVC2019_32bit-Release\release\*.exe %DST%
pause