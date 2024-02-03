// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/core/deprecated.hpp"
OPENVINO_SUPPRESS_DEPRECATED_START

#include "core/node.hpp"
#include "openvino/op/matmul.hpp"

namespace ov {
namespace frontend {
namespace onnx {
namespace op {
namespace detail {
inline ov::OutputVector matmul(const ov::Output<ov::Node>& a, const ov::Output<ov::Node>& b) {
    return {std::make_shared<ov::op::v0::MatMul>(a, b)};
}
}  // namespace detail
namespace set_1 {
inline ov::OutputVector matmul(const ov::frontend::onnx::Node& node) {
    return {std::make_shared<ov::op::v0::MatMul>(node.get_ng_inputs().at(0), node.get_ng_inputs().at(1))};
}
}  // namespace set_1
}  // namespace op
}  // namespace onnx
}  // namespace frontend
}  // namespace ov
OPENVINO_SUPPRESS_DEPRECATED_END
