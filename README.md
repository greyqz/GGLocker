# GGLocker
A simple WinFolder Locker program using C++.

## Description
There are two modes, one is "Unlocked" and the other is "Locked".

Opening the "locked" folder, you can see a inside-view of Windows Recycle bin. To unlock the folder, you must type the right answer.

There are some small functions in "Locked" mode:

- Rename "locked" folder;
- Delete "locked" folder;
- Delete "locked" folder and create a new one.

The answer why "locked" folder is a "Recycle bin" is that if the suffix of a folder is `.{645FF040-5081-101B-9F08-00AA002F954E}`, it will be a shortcut of Recycle bin. So you can display "locked" folder's style by changing the value LOCK_STRING to one of these hereinbelow:

- Control panel: `.{21EC2020-3AEA-1069-A2DD-08002B30309D}`
- Printer: `.{2227A280-3AEA-1069-A2DE-08002B30309D}`
- Recycle bin: `.{645FF040-5081-101B-9F08-00AA002F954E}`
- Webpage: `.{25336920-03F9-11CF-8FD0-00AA00686F13}`
- IE: `.{871C5380-42A0-1069-A2EA-08002B30309D}`
- Network neighborhood: `.{208D2C60-3AEA-1069-A2D7-08002B30309D}`
- Dial-up network: `.{992CFFA0-F557-101A-88EC-00DD010CCC48}`
- Scheduled tasks: `.{D6277990-4C6A-11CF-8D87-00AA0060F5BF}`
- Temporary files: `.{7BD29E00-76C1-11CF-9DD0-00A0C9034933}`

## Simple use
Just copy `GGLocker.exe` to a folder's parent folder. Then double click to open program and type the folder name which you want to lock. To unlock, double click the program and type the folder name which you want to unlock. Type 1 (Unlock once) to unlock, or type 3 (Unlock forever) to unlock the program forever.
