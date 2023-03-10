/**
 * @file protocol_message.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol/protocol_message.h"

prodaq_err_t protocol_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(protocol_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(type);
    PRODAQ_FROM_JSON_BOOLEAN(enabled);
    PRODAQ_FROM_JSON_UNION(config, protocol_config_from_json, ptr->type);
    return PRODAQ_OK;
}

prodaq_err_t protocol_message_to_json(PRODAQ_TO_JSON_PARAMETERS(protocol_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(type);
    PRODAQ_TO_JSON_BOOLEAN(enabled);
    PRODAQ_TO_JSON_UNION(config, protocol_config_to_json, ptr->type);
    return PRODAQ_OK;
}
