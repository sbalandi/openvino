// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/core/deprecated.hpp"
OPENVINO_SUPPRESS_DEPRECATED_START

#include "core/node.hpp"
#include "openvino/op/asin.hpp"

namespace ov {
namespace frontend {
namespace onnx {
namespace op {
namespace set_1 {
inline ov::OutputVector asin(const ov::frontend::onnx::Node& node) {
    return {std::make_shared<ov::op::v0::Asin>(node.get_ng_inputs().at(0))};
}
}  // namespace set_1
}  // namespace op
}  // namespace onnx
}  // namespace frontend
}  // namespace ov
OPENVINO_SUPPRESS_DEPRECATED_END
