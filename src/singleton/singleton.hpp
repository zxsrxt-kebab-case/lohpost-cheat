//
// Created by zxsrxt on 05.06.2025.
//

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>
#include <memory>

template <typename T>
class singleton
{
public:
    singleton( const singleton& ) = delete;
    singleton& operator=( const singleton& ) = delete;

    static std::unique_ptr<T>& get( )
    {
        static std::once_flag flag;
        std::call_once( flag, [ ]( ) {
            instance.reset( new T( ) );
                        } );
        return instance;
    }

protected:
    singleton( ) = default;
    virtual ~singleton( ) = default;

private:
    static inline std::unique_ptr<T> instance;
};

#endif //SINGLETON_HPP
