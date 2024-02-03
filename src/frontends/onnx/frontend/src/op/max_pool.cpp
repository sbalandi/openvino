// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "op/max_pool.hpp"

#include "core/null_node.hpp"
#include "openvino/util/log.hpp"
#include "utils/pooling_factory.hpp"

using namespace ov::op;

OPENVINO_SUPPRESS_DEPRECATED_START
namespace ov {
namespace frontend {
namespace onnx {
namespace op {
namespace set_1 {
ov::OutputVector max_pool(const ov::frontend::onnx::Node& node) {
    if (node.get_outputs_size() > 1) {
        OPENVINO_WARN << "MaxPool: Indices output is not supported and was ignored";
    }
    auto max_pool = pooling::PoolingFactory(node).make_max_pool();
    max_pool.emplace_back(std::make_shared<NullNode>());  // Indices (optional)
    return max_pool;
}

}  // namespace set_1

namespace set_8 {
ov::OutputVector max_pool(const ov::frontend::onnx::Node& node) {
    return pooling::PoolingFactory(node).make_max_pool_with_indices();
}
}  // namespace set_8
}  // namespace op
}  // namespace onnx
}  // namespace frontend
}  // namespace ov
OPENVINO_SUPPRESS_DEPRECATED_END
