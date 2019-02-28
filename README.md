<div style="margin: auto; text-align: center; font-weight: bold;">
  <p style="display:inline;">TodoLIST a.k.a.
  <h1 style="display: inline; font-weight: bold">TIST</h1>
  </p>
</div>

General stuff: <br>
![Language](https://img.shields.io/github/languages/top/Lince99/TodoIST.svg)
![GitHub](https://img.shields.io/github/license/Lince99/TodoIST.svg?logoColor=orange) <br>
Git info: <br>
![Branch](https://img.shields.io/github/last-commit/Lince99/TodoIST.svg)
![GitHub issues](https://img.shields.io/github/issues/Lince99/TodoIST.svg?logoColor=red)
![GitHub closed issues](https://img.shields.io/github/issues-closed/Lince99/TodoIST.svg?logoColor=blue) <br>
Repo stats: <br>
![GitHub repo size in bytes](https://img.shields.io/github/repo-size/Lince99/TodoIST.svg)
![Downloads](https://img.shields.io/github/downloads/Lince99/TodoIST/total.svg) <br>

TIST is a simple todo list manager that have:
* The possibility to show the list in two formats:<br>
    * RAW list<br>
    * CALENDAR ordered by data insertion<br>
<br>
* Functions that accept CSS style for printing the data in .html format<br>
(see "How is it displayed?" section)
* Can be both used in CLI mode, CLI with ncurses or web page mode

### Used libraries:
None

### Dependencies:
<code style="color:#66ffff;">g++</code> for compiling (use <code>apt-get install g++</code> under K/Ubuntu machines)<br>
<code style="color:#66ffff;">make</code> for building (use <code>apt-get install make</code> under K/Ubuntu machines)

---
**FAQ**
======

### Basic usage

Bob<br>
1970/01/01 00:00:00

* **Input:**
```bash
      #             Task                       Due
      tist -t "do homework"
      tist -t "do something else" -d "1970/01/02 00:00:00"
      tist -t "get some good css book" -d now
      tist -t "burn some php book" -d "42/42/4242"
      #
```

* **output:**
```bash
    tist created entry "do homework" with no due (remember every day)
    tist created entry "do something else" with due 1970/01/02 00:00:00
    tist created entry "get some good css book" with due now (alert!)
    tist tryed to create entry "burn some php book": Invalid date!
```

System information (next day)<br>
Bob<br>
1970/01/02 00:00:00

* **input:**
```bash
      tist -v
```

* **output:**
```bash
  Pending dues:
  "do something else" added at 1970/01/01 00:00:00 by Bob
```





### How is it saved?
Save for each day a multiple todo entry with tasks to due like:

```json
{
    "username" : "Bob",
    "creation_date" : {
        "year" : 1970,
        "month" : 1,
        "day" : 1,
        "hour" : 0,
        "minute" : 0,
        "second" : 0
    },
    "pending" : [1234, 5678],
    "entry" : [
        {
            "index" : 1234,
            "text" : "do homework",
            "priority" : 0,
            "due_date" : {
                "year" : null,
                "month" : null,
                "day" : null,
                "hour" : null,
                "minute" : null,
                "second" : null
            }
        },
        {
            "index" : 1234,
            "text" : "do something else",
            "priority" : 1,
            "due_date" : {
                "year" : 1970,
                "month" : 1,
                "day" : 2,
                "hour" : 0,
                "minute" : 0,
                "second" : 0
            }
        },
    ]
}
```
<br>

### How is it displayed?
It can be both viewed via terminal or web interface

<div style="margin-left:10%">
<p>1970/01/01 00:00:00</p>
<div>
    <p>01/01/1970:</p>
    <div><p>NO PENDING DUES</p></div>
    <ul>
        <li>do homework:<p>no due date</p></li>
        <li>do something else:<p>due: 02/01/1970</p></li>
    </ul>
</div>
<p>1970/01/02 00:00:00</p>
<div>
    <p>02/01/1970:</p>
    <div>
      <p style="display:inline;color:#98c379;">"do something else"</p>
      <p style="display:inline;"> added at 1970/01/01 00:00:00 by Bob</p>
    </div>
    <ul>
        <li>get some good css book:
          <p>due: now</p>
        </li>
        <li>burn some php book:
          <p>due: 42/42/4242</p>
        </li>
    </ul>
</div>
</div>
