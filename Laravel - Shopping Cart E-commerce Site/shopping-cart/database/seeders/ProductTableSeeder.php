<?php

namespace Database\Seeders;

use App\Models\Product;
use Illuminate\Database\Seeder;

class ProductTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/61xE71Dq96L._AC_SL1500_.jpg',
            'title' => 'Teddy Bear',
            'description' => 'TEDDY BEAR - Made from high-quality, huggable plush material for a lifetime of hugs and play. FUN FOR ALL AGES. 13” Teddy Bear is machine washable for easy cleaning and appropriate for ages 0+',
            'price' => 15
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/51Emwyvj4%2BL._AC_SL1000_.jpg',
            'title' => 'Panda Bear Plush',
            'description' => 'The fabric：plush. Fill：100% Pure PP cotton. Fine workmanship!',
            'price' => 20
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/61OcxwcDDQL._AC_SL1001_.jpg',
            'title' => 'Shark Plushie',
            'description' => '🐋CUTE PLUSH DOLL SIZE 🐋: 15 inches in length, 12 inches in width, and 8 inches in height. Easy to clean, use a small amount of soap and water to remove stains, and dry naturally. ',
            'price' => 10
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/81HfmDfO-hL._AC_SL1500_.jpg',
            'title' => 'Cute Bunny Plush',
            'description' => 'Butterscotch bunny from b. Toys is a plushy rabbit with a soft peach coat, colorful floppy ears, Rosy cheeks, and bright paws. A cuddly companion filled with love for your little one!',
            'price' => 17
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/71acmIvE26L._AC_SL1200_.jpg',
            'title' => 'Timber Wolf',
            'description' => 'Makes a perfect gift and treasured collectible, 8" wolf is bean bag weighted for cuddling. Realistically detailed using highest quality plush materials - A product of the award winning Bearington Collection',
            'price' => 25
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/41NXl8Z%2B-JL._AC_.jpg',
            'title' => 'Plush Stuffed Squirrel',
            'description' => 'Both realistic and lovely, it expand your children interest and make them love animals more, soft and comfortable to hug, very suitable for play. Super cute stuffed animal toy.',
            'price' => 9
        ]);
        $product->save();

        $product = new Product([
            'imagePath' => 'https://images-na.ssl-images-amazon.com/images/I/51aooUPjcML._AC_SL1000_.jpg',
            'title' => 'Grey Peek-a-boo Elephant',
            'description' => 'High quality: The plush toy made of plush and PP cotton spatula, soft and very comfortable, sensitive to babys skin. Interactive Game Modes: The stuffed elephant has two exciting game modes that entertain and interact with your child for hours.',
            'price' => 30
        ]);
        $product->save();
    }
}
