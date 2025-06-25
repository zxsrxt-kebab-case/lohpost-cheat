#include "il2cpp_field.hpp"

std::string il2cpp_field::get_name( )
{
	return { reinterpret_cast< const char* ( * ) ( il2cpp_field* ) >( IAPI( "il2cpp_field_get_name" ) )( this ) };
}
il2cpp_type *il2cpp_field::get_type()
{
	return reinterpret_cast<il2cpp_type* (*)(il2cpp_field*)>(IAPI("il2cpp_field_get_type"))(this);
}
uint32_t il2cpp_field::get_flags()
{
	return reinterpret_cast<uint32_t (*)(il2cpp_field*)>(IAPI("il2cpp_field_get_flags"))(this);
}
int32_t il2cpp_field::get_offset()
{
	return reinterpret_cast<int32_t(*)(il2cpp_field*)>(IAPI("il2cpp_field_get_offset"))(this);
}

