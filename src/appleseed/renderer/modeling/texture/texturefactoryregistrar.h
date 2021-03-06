
//
// This source file is part of appleseed.
// Visit https://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2013 Francois Beaune, Jupiter Jazz Limited
// Copyright (c) 2014-2018 Francois Beaune, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

// appleseed.foundation headers.
#include "foundation/utility/api/apiarray.h"
#include "foundation/utility/searchpaths.h"

// appleseed.main headers.
#include "main/dllsymbol.h"

// Forward declarations.
namespace renderer  { class ITextureFactory; }
namespace renderer  { class Plugin; }
namespace renderer  { class Texture; }

namespace renderer
{

//
// An array of texture factories.
//

APPLESEED_DECLARE_APIARRAY(TextureFactoryArray, ITextureFactory*);


//
// Texture factory registrar.
//

class APPLESEED_DLLSYMBOL TextureFactoryRegistrar
{
  public:
    typedef Texture EntityType;
    typedef ITextureFactory FactoryType;
    typedef TextureFactoryArray FactoryArrayType;

    // Constructor.
    explicit TextureFactoryRegistrar(
        const foundation::SearchPaths& search_paths = foundation::SearchPaths());

    // Destructor.
    ~TextureFactoryRegistrar();

    // Register a factory defined in a plugin.
    void register_factory_plugin(Plugin* plugin, void* plugin_entry_point);

    // Retrieve the registered factories.
    FactoryArrayType get_factories() const;

    // Lookup a factory by name.
    const FactoryType* lookup(const char* name) const;

  private:
    struct Impl;
    Impl* impl;
};

}   // namespace renderer
