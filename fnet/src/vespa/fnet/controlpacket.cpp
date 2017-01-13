// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#include "controlpacket.h"
#include "context.h"
#include <vespa/vespalib/util/stringfmt.h>

void
FNET_ControlPacket::Free()
{
}

bool
FNET_ControlPacket::IsRegularPacket()
{
    return false;
}

bool
FNET_ControlPacket::IsControlPacket()
{
    return true;
}

uint32_t
FNET_ControlPacket::GetCommand()
{
    return _command;
}

bool
FNET_ControlPacket::IsChannelLostCMD()
{
    return _command == FNET_CMD_CHANNEL_LOST;
}

bool
FNET_ControlPacket::IsTimeoutCMD()
{
    return _command == FNET_CMD_TIMEOUT;
}

bool
FNET_ControlPacket::IsBadPacketCMD()
{
    return _command == FNET_CMD_BAD_PACKET;
}

uint32_t
FNET_ControlPacket::GetPCODE()
{
    return FNET_NOID;
}

uint32_t
FNET_ControlPacket::GetLength()
{
    return 0;
}

void
FNET_ControlPacket::Encode(FNET_DataBuffer *)
{
    abort();
}

bool
FNET_ControlPacket::Decode(FNET_DataBuffer *, uint32_t)
{
    abort(); return false;
}

vespalib::string
FNET_ControlPacket::Print(uint32_t indent)
{
    return vespalib::make_string("%*sFNET_ControlPacket { command = %d }\n",
                                 indent, "", _command);
}

FNET_ControlPacket
FNET_ControlPacket::NoCommand(FNET_CMD_NOCOMMAND);

FNET_ControlPacket
FNET_ControlPacket::ChannelLost(FNET_CMD_CHANNEL_LOST);

FNET_ControlPacket
FNET_ControlPacket::IOCAdd(FNET_CMD_IOC_ADD);

FNET_ControlPacket
FNET_ControlPacket::IOCEnableRead(FNET_CMD_IOC_ENABLE_READ);

FNET_ControlPacket
FNET_ControlPacket::IOCDisableRead(FNET_CMD_IOC_DISABLE_READ);

FNET_ControlPacket
FNET_ControlPacket::IOCEnableWrite(FNET_CMD_IOC_ENABLE_WRITE);

FNET_ControlPacket
FNET_ControlPacket::IOCDisableWrite(FNET_CMD_IOC_DISABLE_WRITE);

FNET_ControlPacket
FNET_ControlPacket::IOCClose(FNET_CMD_IOC_CLOSE);

FNET_ControlPacket
FNET_ControlPacket::Execute(FNET_CMD_EXECUTE);

FNET_ControlPacket
FNET_ControlPacket::Timeout(FNET_CMD_TIMEOUT);

FNET_ControlPacket
FNET_ControlPacket::BadPacket(FNET_CMD_BAD_PACKET);
