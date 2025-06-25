#pragma once
#include "../common.hpp"
#include "../il2cpp_field/il2cpp_field.hpp"
#include "../il2cpp_method/il2cpp_method.hpp"
class il2cpp_class
{
private:
	il2cpp_field* get_fields_internal( void** iter );
	il2cpp_method* get_methods_internal( void** iter );

public:
	std::string get_name( );
	std::string get_namespace( );
	std::vector<il2cpp_field*> get_fields( );
	std::vector<il2cpp_method*> get_methods( );
	il2cpp_field* get_field( const std::string& name );
	il2cpp_field* get_field( std::uint32_t flags, uint32_t index = 0 ); //not works fuck
	il2cpp_method* get_method( std::string name, int params = 0 );
	il2cpp_method* get_method( std::string name, std::initializer_list<std::string> params = { } );
	uintptr_t get_static_fields();
	template<typename T = void*>
	T new_object( )
	{
		return reinterpret_cast< T( * ) ( il2cpp_class* ) >( IAPI( "il2cpp_object_new" ) )( this );
	}
};

