#include "il2cpp_class.hpp"

#include <ranges>

#include "il2cpp-tabledefs.h"
#include "resolve_enum.hpp"
#include "../il2cpp_type/enum_type.hpp"

il2cpp_field* il2cpp_class::get_fields_internal( void** iter )
{
	return reinterpret_cast< il2cpp_field * ( * )( il2cpp_class*, void** ) >( IAPI( "il2cpp_class_get_fields" ) )( this, iter );
}
il2cpp_method* il2cpp_class::get_methods_internal( void** iter )
{
	return reinterpret_cast< il2cpp_method * ( * )( il2cpp_class*, void** ) >( IAPI( "il2cpp_class_get_methods" ) )( this, iter );
}

std::string il2cpp_class::get_name( )
{
	return { reinterpret_cast< const char* ( * ) ( il2cpp_class* ) >( IAPI( "il2cpp_class_get_name" ) )( this ) };
}
std::string il2cpp_class::get_namespace( )
{
	return { reinterpret_cast< const char* ( * ) ( il2cpp_class* ) >( IAPI( "il2cpp_class_get_namespace" ) )( this ) };
}

std::vector<il2cpp_field*> il2cpp_class::get_fields( )
{
	std::vector< il2cpp_field* > ret;

	void* iter = nullptr;
	while ( auto field = get_fields_internal( &iter ) )
	{
		ret.push_back( field );
	}

	return ret;
}
il2cpp_field* il2cpp_class::get_field( const std::string& name )
{
	for ( const auto& field : get_fields( ) )
	{
		if ( field->get_name( ) != name )
			continue;

		return field;
	}
	return reinterpret_cast< il2cpp_field * ( * )( il2cpp_class*, const char* ) >( IAPI( "il2cpp_class_get_field_from_name" ) )( this, name.c_str( ) );
}


// SHIT NOT WORKS I WASTED ALL NIGHT WRITING THIS STUFF FUCKKKKDLDSKDKKSKDKKDSKD
il2cpp_field* il2cpp_class::get_field(uint32_t flags, uint32_t index)
{
    auto fields = get_fields();
    uint32_t current_index = 0;

    const auto it = std::ranges::find_if(fields, [flags, index, &current_index](il2cpp_field* field) -> bool
    {
        bool type_match = false;
        switch (field->get_type()->get_type())
        {
            case IL2CPP_TYPE_BOOLEAN:  type_match = flags & field_boolean; break;
            case IL2CPP_TYPE_R4:       type_match = flags & field_float; break;
            case IL2CPP_TYPE_CLASS:    type_match = flags & field_pointer; break;
            case IL2CPP_TYPE_ENUM:     type_match = flags & field_enum; break;
            case IL2CPP_TYPE_STRING:   type_match = flags & field_string; break;
            case IL2CPP_TYPE_ARRAY:	   type_match = flags & field_array; break;
            case IL2CPP_TYPE_I1: case IL2CPP_TYPE_U1:
            case IL2CPP_TYPE_I2: case IL2CPP_TYPE_U2:
            case IL2CPP_TYPE_I4: case IL2CPP_TYPE_U4:
            case IL2CPP_TYPE_I8: case IL2CPP_TYPE_U8: type_match = flags & field_integer; break;
            default: return false;
        }

        if (!type_match) return false;

        const auto attrs = field->get_flags();

        if (flags & field_static && !(attrs & FIELD_ATTRIBUTE_STATIC))
            return false;

        if (flags & field_readonly && !(attrs & FIELD_ATTRIBUTE_INIT_ONLY))
            return false;

        const auto access = attrs & FIELD_ATTRIBUTE_FIELD_ACCESS_MASK;
        bool access_match = false;

        switch (access)
        {
            case FIELD_ATTRIBUTE_PRIVATE:    access_match = flags & field_private; break;
            case FIELD_ATTRIBUTE_PUBLIC:    access_match = flags & field_public; break;
            case FIELD_ATTRIBUTE_FAMILY:    access_match = flags & field_protected; break;
            case FIELD_ATTRIBUTE_FAM_AND_ASSEM: access_match = flags & field_internal; break;
            default: access_match = false;
        }

        if (!access_match) return false;

        if (index != 0 && ++current_index != index)
            return false;

        return true;
    });

	if (it == fields.end( ))
		return nullptr;

    return *it;
}

std::vector<il2cpp_method*> il2cpp_class::get_methods( )
{
	std::vector< il2cpp_method* > ret;

	void* iter = nullptr;
	while ( auto method = get_methods_internal( &iter ) )
	{
		if(std::ranges::find(ret, method) == ret.end( ))
			ret.push_back( method );
	}

	return ret;
}
il2cpp_method* il2cpp_class::get_method( std::string name, int params )
{
	return reinterpret_cast< il2cpp_method * ( * )( il2cpp_class*, const char*, int ) >( IAPI( "il2cpp_class_get_method_from_name" ) )( this, name.c_str( ), params );
}
il2cpp_method* il2cpp_class::get_method( std::string name, std::initializer_list<std::string> params )
{
	if ( params.size( ) == 0 )
		return get_method( name, 0 );
	
	auto methods = get_methods( );

	auto method_matches = [ &name, &params ]( il2cpp_method* method ) {
		if ( method->get_name( ) != name )
			return false;

		uint32_t param_count = method->get_param_count( );
		if ( param_count != params.size( ) )
			return false;

		auto param_it = params.begin( );
		for ( uint32_t idx = 0; idx < param_count; ++idx, ++param_it )
		{
			if ( method->get_param_name( idx ) != *param_it )
				return false;
		}

		return true;
		};

	auto it = std::ranges::find_if( methods, method_matches );

	if ( it != methods.end( ) )
	{
		return *it;
	}

	return nullptr;
}

uintptr_t il2cpp_class::get_static_fields()
{
	return *reinterpret_cast<uintptr_t*>( reinterpret_cast<uintptr_t>(this) + 0xb8 );
}
