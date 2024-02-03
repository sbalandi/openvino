// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "op/image_scaler.hpp"

#include "openvino/frontend/exception.hpp"
#include "openvino/op/add.hpp"
#include "openvino/op/constant.hpp"
#include "openvino/op/multiply.hpp"

using namespace ov::op;

OPENVINO_SUPPRESS_DEPRECATED_START
namespace ov {
namespace frontend {
namespace onnx {
namespace op {
namespace set_1 {
ov::OutputVector image_scaler(const ov::frontend::onnx::Node& node) {
    const auto inputs = node.get_ng_inputs();
    FRONT_END_GENERAL_CHECK(inputs.size() == 1, "ImageScaler 1 input tensor. Got: ", inputs.size());

    const auto data = inputs[0];
    const auto& data_shape = data.get_partial_shape();
    FRONT_END_GENERAL_CHECK(data_shape.rank().same_scheme({4}),
                            "ImageScaler expects a 4D tensor with NCHW format. Got: ",
                            data_shape);

    const auto bias = node.get_attribute_value<std::vector<float>>("bias");

    FRONT_END_GENERAL_CHECK(data_shape[1].same_scheme(bias.size()),
                            "Number of bias attribute elements: ",
                            bias.size(),
                            " does not match the channel dimension: ",
                            data_shape[1].get_length());

    const auto scale_const = node.get_attribute_as_constant<float>("scale", 1.0, data.get_element_type());

    const auto bias_const = v0::Constant::create(data.get_element_type(), {1, bias.size(), 1, 1}, bias);

    const auto scaler = std::make_shared<v1::Add>(std::make_shared<v1::Multiply>(data, scale_const), bias_const);

    return {scaler};
}
}  // namespace set_1
}  // namespace op
}  // namespace onnx
}  // namespace frontend
}  // namespace ov
OPENVINO_SUPPRESS_DEPRECATED_END
