#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "typelistisempty.hpp"

template<typename List, template<typename T> class MetaFun, bool Empty = IsEmpty<List>::value>
class TransformT {
public:
    using Type = List;
};

// recursive case:
template<typename List, template<typename T> class MetaFun>
class TransformT<List, MetaFun, false>
   : public PushFrontT<typename TransformT<PopFront<List>, MetaFun>::Type,
                       typename MetaFun<Front<List>>::Type>
{};

template<typename List, template<typename T> class MetaFun>
using Transform = typename TransformT<List, MetaFun>::Type;

#endif