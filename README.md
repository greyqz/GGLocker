# GGLocker
A simple WinFolder Locker program using C++.

## Usage
1. Copy `GGLocker.exe` to a folder's parent folder. 
2. Double click to open program and type the folder name which you want to lock.
3. Type 1 (Set a password and lock) to set a password. The folder will be locked.
4. To unlock, double click the program and type the folder name which you want to unlock. Type 1 (Unlock once) to unlock, or type 3 (Unlock forever) to unlock the program forever.

## Description
There are two modes, one is "Unlocked" and the other is "Locked".

### "Unlocked" mode
You can add password and lock the folder by typing 1 (Set a password and lock). The password can be more than one line.

This is a password example:

``` plain
Line 1> A quick brown fox
Line 2> Jumped over the lazy dog.
Line 3> !!!
```

If you are afraid of losing password, you can create a password hint file directly in the parent folder.

### "Locked" mode

Opening the "locked" folder, you can see the inside of Windows Recycle bin. To unlock the folder, you must type the right password line by line. Type a line "!!!" as the end of password.

There are some small functions in "Locked" mode:

- Rename "locked" folder;
- Delete "locked" folder;
- Delete "locked" folder and create a new one.

## Principle

The answer why "locked" folder is a "Recycle bin" is that if the suffix of a folder is `.{645FF040-5081-101B-9F08-00AA002F954E}`, it will be a shortcut of Recycle bin. So you can display "locked" folder's style by changing the value `LOCK_STRING` in the source code to one of these hereinbelow:

- Control panel: `.{21EC2020-3AEA-1069-A2DD-08002B30309D}`
- Printer: `.{2227A280-3AEA-1069-A2DE-08002B30309D}`
- Recycle bin: `.{645FF040-5081-101B-9F08-00AA002F954E}`
- Webpage: `.{25336920-03F9-11CF-8FD0-00AA00686F13}`
- IE: `.{871C5380-42A0-1069-A2EA-08002B30309D}`
- Network neighborhood: `.{208D2C60-3AEA-1069-A2D7-08002B30309D}`
- Dial-up network: `.{992CFFA0-F557-101A-88EC-00DD010CCC48}`
- Scheduled tasks: `.{D6277990-4C6A-11CF-8D87-00AA0060F5BF}`
- Temporary files: `.{7BD29E00-76C1-11CF-9DD0-00A0C9034933}`

The password is saved directly in the locked folder.

To unlock the folder without a password, you need to run Windows Command as administrator, and type these codes below (change "parent_folder" to your locked folder's parent folder; change "folder" to the locked folder):

``` cmd
cd /d "parent_folder"
rename "folder.{645FF040-5081-101B-9F08-00AA002F954E}" "folder"
```
