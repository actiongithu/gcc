// { dg-do compile { target c++11 } }

// Copyright (C) 2013-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <list>

void test01() 
{
  std::list<int> l1;
  l1.push_back(1);
  l1.erase(l1.cbegin());

  std::list<int> l2;
  l2.push_back(2);
  l2.push_back(3);
  l2.erase(l2.cbegin(), l2.cend());
}
