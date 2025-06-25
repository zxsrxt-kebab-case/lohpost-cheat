#pragma once
#include "../il2cpp_image/il2cpp_image.hpp"

#define ASSEMBLY "Assembly-CSharp"

class il2cpp_assembly
{
public:
	static il2cpp_assembly* open( std::string ass );
	il2cpp_image* image( );
};

