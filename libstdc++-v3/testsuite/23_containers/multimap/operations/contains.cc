// Copyright (C) 2018-2025 Free Software Foundation, Inc.
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

// { dg-do run { target c++20 } }

#include <map>
#include <testsuite_hooks.h>

void
test01()
{
  std::multimap<int, void*> m;
  VERIFY( ! m.contains( 0 ) );
  VERIFY( ! m.contains( 1 ) );
  m.emplace(0, nullptr);
  VERIFY( m.contains( 0 ) );
  VERIFY( ! m.contains( 1 ) );
  m.emplace(0, nullptr);
  VERIFY( m.contains( 0 ) );
  VERIFY( ! m.contains( 1 ) );
  m.emplace(1, nullptr);
  VERIFY( m.contains( 0 ) );
  VERIFY( m.contains( 1 ) );
}

struct Zero { };
bool operator<(Zero, int i) { return 0 < i; }
bool operator<(int i, Zero) { return i < 0; }

struct One { };
bool operator<(One, int i) { return 1 < i; }
bool operator<(int i, One) { return i < 1; }

void
test02()
{
  std::multimap<int, void*, std::less<>> m;
  VERIFY( ! m.contains( Zero{} ) );
  VERIFY( ! m.contains( One{} ) );
  m.emplace(0, nullptr);
  VERIFY( m.contains( Zero{} ) );
  VERIFY( ! m.contains( One{} ) );
  m.emplace(0, nullptr);
  VERIFY( m.contains( Zero{} ) );
  VERIFY( ! m.contains( One{} ) );
  m.emplace(1, nullptr);
  VERIFY( m.contains( Zero{} ) );
  VERIFY( m.contains( One{} ) );
}

int
main()
{
  test01();
  test02();
}
