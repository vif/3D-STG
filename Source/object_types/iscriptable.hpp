#pragma once

#include "iupdatable.hpp"
#include "imodelrender.hpp"

class IScriptable: public IModelRender, public IUpdatable{};