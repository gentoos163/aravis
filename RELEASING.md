# Release of Aravis

Here are the steps to follow to create a new aravis release:

* Ensure that there are no local, uncommitted/unpushed
  modifications. You're probably in a good state if both `git diff
  HEAD` and `git log master..origin/master` give no output.

* Fill out an entry in the **NEWS.md** file

  Sift through the logs since the last release. This is most
  easily done with a command such as:

  ```
git log --stat X.Y.Z..
  ```

  where X.Y.Z is the previous release version.

  Summarize major changes briefly in a style similar to other
  entries in NEWS. Take special care to note any additions in
  the API. These should be easy to find by noting modifications
  to .h files in the log command above.

* Verify that the code passes `ninja dist`

  Running `ninja dist` should result in no warnings or
  errors and end with a message of the form:

  ```
Distribution package /home/pacaud/Sources/aravis/build/meson-dist/aravis-0.7.2.tar.xz tested
  ```

  (But the tar file isn't actually ready yet, as we still have
  some more steps to follow).

* Tag the release; This will allow you to make a branch later if you so desire
  but for now, at least it make it easy to see what was included in a particular
  release. The commit message for the tag will be included in a changes file in
  the release directory.

  ```
$ git tag -a ARAVIS_X_Y_Z (from whatever branch you're releasing)
$ git push origin ARAVIS_X_Y_Z
  ```

  If that fails because someone has pushed since you last updated, then you'll
  need to repeat the entire process. Well, update, add a new NEWS entry, and
  make distcheck again.

* Upload the tarball to ftp.gnome.org, by scp-ing it to master.gnome.org. All
  module maintainers who wish to be able to upload tarballs should request a
  shell account at master.gnome.org for this purpose -- see AccountPolicy.
  Ask someone else to do it for you if you are waiting for an account.

  For example:

  ```
$ scp aravis-0.1.3.tar.gz (user)@master.gnome.org:
  ```

  Then `ssh` into `master.gnome.org` and call `ftp-admin`. There are no extra
  steps required for new modules.

  For example:

  ```
$ ftpadmin install aravis-0.1.3.tar.gz
  ```

  This will move the tarball to the appropriate directory, do some additional
  administrative stuff, and send an email to the ftp-release mailing list so
  that the release-team will know about it.

* Increment the version number in `meson.build`, and push the change.

* Create a new topic on https://aravis-project.discourse.org to announce the new
  release adding the excerpt from NEWS, your signature, followed
  by the standard "What is aravis" and "Where to get more information
  about aravis" blurbs from README, and finally the shortlog of all
  changes since last release, generated by:

  ```
git shortlog ARAVIS_X_Y_Z...
  ```

  where ARAVIS_X_Y_Z is the last released version.
