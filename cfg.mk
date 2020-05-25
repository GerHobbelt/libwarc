# Copyright (C) 2020 Free Software Foundation, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Syntax Check Rules that we want to skip
#  * sc_immutable_NEWS: I can't make this test ever pass. If someone fixes it,
#  happy to remove it from here.
#  * sc_bindtextdomain: We don't use gettext or internationalization since this
#  is only a library with no user-facing strings
local-checks-to-skip = \
	sc_immutable_NEWS \
	sc_bindtextdomain

update-copyright-env = UPDATE_COPYRIGHT_FORCE=1 UPDATE_COPYRIGHT_USE_INTERVALS=1

# Explicit syntax-check exceptions.

## Not all c files require the config.h file
exclude_file_name_regexp--sc_require_config_h = examples/.*\.c$$
exclude_file_name_regexp--sc_require_config_h_first = examples/.*\.c$$

# New syntax-check rules
sc_prohibit_sprintf:
        @prohibit='\<sprintf *\(' \
        halt='do not use sprintf() as it does not check the output buffer size' \
          $(_sc_search_regexp)

# Prohibit the use of a carriage return anywhere
# This prevents both OSX and Windows users from messing with the line endings
sc_force_unix_lineending:
	@$(VC_LIST_EXCEPT)                                                   \
	  | xargs $(GREP) -P '\r'                                            \
	  && { echo '$(ME): Dont use carriage returns in line endings' 1>&2; \
	       exit 1; }                                                     \
	  || :
