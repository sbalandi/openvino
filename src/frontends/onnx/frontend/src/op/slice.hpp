// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/core/deprecated.hpp"
OPENVINO_SUPPRESS_DEPRECATED_START

#include "core/node.hpp"

namespace ov {
namespace frontend {
namespace onnx {
namespace op {
namespace set_10 {
ov::OutputVector slice(const ov::frontend::onnx::Node& node);

}  // namespace set_10

namespace set_1 {
ov::OutputVector slice(const ov::frontend::onnx::Node& node);

}  // namespace set_1
}  // namespace op
}  // namespace onnx
}  // namespace frontend
}  // namespace ov
OPENVINO_SUPPRESS_DEPRECATED_END
