#pragma once

#include "RequestTypes.h"
#include <InventoryChanger/Backend/Response/Response.h>

namespace inventory_changer::backend
{

class BackendSimulator;
class PickEm;

struct RequestHandler {
    RequestHandler(BackendSimulator& backend, PickEm& pickEm, ItemConstRemover constRemover)
        : backend{ backend }, pickEm{ pickEm }, constRemover{ constRemover } {}

    Response operator()(const request::ApplySticker& request) const;
    Response operator()(const request::WearSticker& request) const;
    Response operator()(const request::SwapStatTrak& request) const;
    Response operator()(const request::OpenContainer& request) const;
    Response operator()(const request::ApplyPatch& request) const;
    Response operator()(const request::RemovePatch& request) const;
    Response operator()(const request::ActivateOperationPass& request) const;
    Response operator()(const request::ActivateViewerPass& request) const;
    Response operator()(const request::AddNameTag& request) const;
    Response operator()(const request::RemoveNameTag& request) const;
    Response operator()(const request::ActivateSouvenirToken& request) const;
    Response operator()(const request::UnsealGraffiti& request) const;
    Response operator()(const request::UpdateStatTrak& request) const;
    Response operator()(const request::SelectTeamGraffiti& request) const;
    Response operator()(const request::MarkItemUpdated& request) const;
    Response operator()(const request::PickStickerPickEm& request) const;

private:
    BackendSimulator& backend;
    PickEm& pickEm;
    ItemConstRemover constRemover;
};

}
