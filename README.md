
# EPC (Edusoft - Process - Calendar)


This is a project which I came up with when I was feeling so sad, I had forgot my schedule.
So I make it to get Google Calendar notify me when I have class on my college.


## Authors

- [@onecedrus](https://github.com/1cedrus)
- [@hisbrother](https://github.com/sinzii)


## Guide
To use this tool, first of all, you must crawl data about your schedule on your school's edusoft website. 
 
Let  crawler do it for you. Open sessionID.ssid file and write your sessionID at there. Remember to change schedule to your personal semester and set schedule view to "sap-xep-theo-thu-tiet".
And run crawler tool. All your schedule will be store in rawSubject.json.

Next, run epc tool, paste your authorization code to console and enter. All your schedule will be update to Google Calendar.

Finally, don't for get to recheck your schedule.


## Installation

Install curl and json-c

```bash
$ sudo apt update
$ sudo apt upgrade
$ sudo apt-get install libcurl4-gnutls-dev libjson-c-dev
```
    
Install epc and crawler

Clone this repo to your computer. In folder of either epc or crawler. Run:

```bash
$ make
```


## Thanks you!

That's all. If you coming across with some bug. Send me that. Happy to help you.

## Updating...

More automatic and ez to use. Pls watting
