<div align="center">
  <a href="https://www.sadiqpk.org/projects/my-gtemplate.html">
    <img src="https://gitlab.com/sadiq/my-gtemplate/raw/master/data/icons/hicolor/256x256/apps/org.sadiqpk.GTemplate.png" width="150" />
  </a>
  <br>

  <a href="https://www.sadiqpk.org/projects/my-gtemplate.html"><b>My GTemplate</b></a>
  <br>

  A Simple feature rich GTK3/GTK4 Application template in C
  <br>

  <a href="https://gitlab.com/sadiq/my-gtemplate/pipelines"><img
       src="https://gitlab.com/sadiq/my-gtemplate/badges/master/pipeline.svg" /></a>
  <a href="https://sadiq.gitlab.io/my-gtemplate/coverage"><img
       src="https://gitlab.com/sadiq/my-gtemplate/badges/master/coverage.svg" /></a>
</div>

---

My GTemplate is a simple GTK Application that can be used as a
template to begin your GTK Application developement.

By default, the template itself does nothing other than showing
an empty window.
The template includes lots of features above which you can build
your own application.

If you wish to support me, you may kindly donate me at
https://liberapay.com/sadiq/donate

Source Repository: [GitLab][gitlab], [GitHub][github]

Issues and Feature Requests: [GitLab][issues]

Please visit the [website][home] for more details.

## License

Despite of whatever some source file contain as License blurb,
All code included in this repository are **released into Public
Domain**.  If you wish to contribute to this project, it is assumed
that you are contributing under the same terms below.

Some source files have GNU GPLv3+ blurb to simply ease creating
free software projects.  If you wish to use a different license
term for you project, go for it.  Don’t even mention me.

Written in 2017-2023 by Mohammed Sadiq <sadiq@sadiqpk.org>

To the extent possible under law, the author(s) have dedicated all
copyright and related and neighboring rights to this software to
the public domain worldwide.  This software is distributed without
any warranty.

You should have received a copy of the CC0 Public Domain Dedication
along with this software.  If not, see
<http://creativecommons.org/publicdomain/zero/1.0/>.


## Features

* Written in C programming language
* [G]Object Oriented Design
* Supports GTK3 and GTK4
* Uses Meson build system
* Builtin flatpak support
* GitLab CI configuration included (Gtk3 only)
* Microsoft Windows support with MinGW and msitools
* GtkBuilder .ui templates for UI
* Application specific CSS
* Keyboard shortcuts window
* Handles commandline arguments
* Tab completion for commandline
* Internationalisation using gettext
* Documentations for code using `gtk-doc`
  * This will be added to `devhelp` on install.
* Mallard based help using `yelp` (That is, GNOME Help)
* Manpage in docbook XML format
* GSettings integration
  * window states (size, position and maximized state) are stored
    and loaded by default
* Symbolic and non-symbolic icons
* Script to generate png icons from scalable icons
* Script to generate non-symbolic icons from symbolic ones
* Uncrustify configuration and script
* Meson based unit tests


## Building My GTemplate

Install required dependencies.

On Debian and derivatives (like Ubuntu):
* `sudo apt install -y build-essential meson libgtk-4-dev \
  appstream-util xsltproc docbook-xsl bash-completion \
  gettext uncrustify libadwaita-1-dev`

On Fedora and derivatives:
* `sudo dnf install -y @c-development @development-tools \
  gettext-devel gtk4-devel meson desktop-file-utils \
  docbook-style-xsl uncrustify bash-completion libxslt \
  itstool libadwaita-devel`

`meson` is used as the build system.  Run the following to build:
* `meson build`
* `cd build && ninja`
* `sudo ninja install # To install` 

Here `build` is a non-existing directory name.  You may use any
name of your choice.

## Running My GTemplate

If you have installed application:
* `my-gtemplate`

If you want to run the application without installing:
* do `./run` from the build directory

You can add `-v` multiple times to get verbose logs:
* `./run -vvvv`

### Detailing the paths and files

```
my-gtemplate
├── build-aux ── Helper scripts for build
├── completion
│   └── my-gtemplate ── Add your commandline TAB completions in this file
├── COPYING ── By default GNU GPLv3.  Use the one you wish
├── data
│   ├── icons
│   │   ├── hicolor
│   │   │   ├── render-icons.sh ── Run this script once you add app icon
│   │   │   ├── scalable ── Add your Application icon here
│   │   │   │   └── apps
│   │   │   │       └── org.sadiqpk.GTemplate.svg
│   │   │   └── symbolic
│   │   │       └── apps
│   │   │           └── org.sadiqpk.GTemplate-symbolic.svg ── symbolic version
│   ├── org.sadiqpk.GTemplate.desktop.in
│   └── org.sadiqpk.gtemplate.gschema.xml
├── docs
│   ├── help ──
│   │   ├── C
│   │   │   └── index.page ── Add the help pages shown in GNOME Help
│   │   ├── LINGUAS ── Automatilly updated with ~ninja make-help-po~
│   ├── man
│   │   └── my-gtemplate.xml
│   └── reference
│       ├── my-gtemplate-docs.xml
│       └── my-gtemplate-sections.txt
├── flatpak
│   └── org.sadiqpk.GTemplate.yml
├── po
│   ├── LINGUAS ── List of languages for which translations are included.
│   └── POTFILES.in ── List of files to be considered for translation
├── README.org
├── src ── The real source of your application
│   └── resources
│       ├── css
│       │   └── mgt.css
│       ├── gtemplate.gresource.xml
│       ├── gtk
│       │   ├── help-overlay.ui
│       └── ui
│           └── mgt-window.ui
├── tests
│   └── settings.c ── Simple test to show how to add one
├── uncrustify.cfg
└── uncrustify.sh ── Script to keep your code clean and tidy
```

<!-- Links referenced elsewhere -->
[home]: https://www.sadiqpk.org/projects/my-gtemplate.html
[coverage]: https://sadiq.gitlab.io/my-gtemplate/coverage
[gitlab]: https://gitlab.com/sadiq/my-gtemplate
[github]: https://github.com/pksadiq/my-gtemplate
[issues]: https://gitlab.com/sadiq/my-gtemplate/issues
