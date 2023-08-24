using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClearCounter : BaseCounter
{
    [SerializeField] private KitchenObjectSO kitchenObjectSO;         // Can also use GameObject


    public override void Interact(Player player)
    {
        if (!HasKitchenObject())
        {
            // If there is no KitchenObject, Check if the player has any KitchenObject
            if (player.HasKitchenObject())
            {
                // Player has a KitchenObject
                player.GetKitchenObject().SetKitchenObjectParent(this);
            }
            else
            {
                // Player has no KitchenObject, Do nothing
            }
        }
        else
        {
            // Already has a KitchenObject, Check if the player has a KitchenObject
            if (player.HasKitchenObject())
            {
                // Player has a KitchenObject
                if(player.GetKitchenObject().TryGetPlate(out PlateKitchenObject plateKitchenObject))
                {
                    // Player is holding a Plate
                    if (plateKitchenObject.TryAddIngredient(GetKitchenObject().GetKitchenObjectSO()))
                    {
                        KitchenObject.DestroyKitchenObject(GetKitchenObject()); // Destroy what is on the counter
                    }
                    
                }
                else
                {
                    // Player is holding a KitchenObject that is not a Plate
                    if(GetKitchenObject().TryGetPlate(out plateKitchenObject))
                    {
                        // Counter has a plate
                        if (plateKitchenObject.TryAddIngredient(player.GetKitchenObject().GetKitchenObjectSO()))
                        {
                            KitchenObject.DestroyKitchenObject(player.GetKitchenObject());
                        }

                    }

                }

            }
            else
            {
                // Player has no KitchenObject, Pickup from the Clear Counter
                GetKitchenObject().SetKitchenObjectParent(player);
            }

        }

    }

}