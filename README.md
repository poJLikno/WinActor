# WinActor #
### WinActor — Activator for Microsoft Windows 10/11 ***(Pro/Home)*** and Microsoft Office, that uses KMS services. ###

## How to use? ##
The App works in silent mode and has 4 flags:
  - 2 flags -- Select target:
      * -w --> Select Windows
      * -o --> Select Office
  - 2 flags -- Change programm purpose:
      * -c --> Clear product key, remove KMS
      * -r --> Reactivation

`$ WinActor.exe [flags]`

## Activation ##
Use `$ WinActor.exe -w` or `$ WinActor.exe -wo` to activate Windows (& Office)

## Remove ##
If you want remove products keys, you can use `$ WinActor.exe -cwo`

## Reactivation ##
KMS services working for 180 days, reactivation is necessary.
** -r ** flag allow you to do reactivation of product.
App uses flag -c to remove key, then app activates product again

So, App works in silent mode.
It's very useful cause don't distract while user work.
You can create schedule task using command in bat-file and xml-configuration of task. ***(Need Administrator rules)***
Or you can run ```WinActorInstaller.exe``` to create **C:\Windows\WinActor** directory and create reactivation schedule task. ***(Run with Administrator rules)***
Reactivation will run every 10 days.

## Check Activation state ##
Use supplied bat-files to check activation state. ***(Need Administrator rules)***

## Download ##
Click here to download [Release](https://github.com/poJLikno/WinActor/releases)
